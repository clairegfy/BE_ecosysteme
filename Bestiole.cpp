#include "Bestiole.h"

#include "Milieu.h"
#include "ICapteur.h"
#include "IAccessoire.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
const int Bestiole::AGE_MAX = 500;
const double Bestiole::PROBA_CLONAGE = 0.001;  // 0.1% de chance par pas de temps de clonage spontané

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   _comportement = nullptr;
   age    = 0;
   ageMax = 100 + std::rand() % AGE_MAX;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );
   _comportement = (b._comportement != nullptr) ? b._comportement->clone() : nullptr;
   for ( ICapteur* c : b.capteurs )
        capteurs.push_back( c->clone() );

   for ( IAccessoire* a : b.accessoires )
        accessoires.push_back( a->clone() );

   for ( ICapteur* c : b.capteurs )
      capteurs.push_back( c->clone() );

   for ( IAccessoire* a : b.accessoires )
      accessoires.push_back( a->clone() );

   age    = 0;        //repart à 0 pour une nouvelle bestiole
   ageMax = b.ageMax;

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;
   delete _comportement;

   for ( ICapteur* c : capteurs )
      delete c;
    capteurs.clear();

   for ( IAccessoire* a : accessoires )
      delete a;
    accessoires.clear();

   cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         vitesseEffective = getVitesseEffective();
   double         dx = cos( orientation )*vitesseEffective;
   double         dy = -sin( orientation )*vitesseEffective;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

void Bestiole::draw( UImg & support )
{
    unsigned char r, g, b;
    _comportement->getCouleur(r, g, b);
    const unsigned char couleur[] = { r, g, b };
   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{
   return detecte( b );
}

void Bestiole::setComportement( Comportement* c )
{
    delete _comportement;   // libère l'ancien
    _comportement = c;
}

void Bestiole::action( Milieu & monMilieu, std::vector<Bestiole*> & aAjouter )
{

    age++; //incrémentation de l'âge de la bestiole

    // auto-clonage spontané
    double probaClonage = static_cast<double>( std::rand() ) / RAND_MAX;
    if ( probaClonage < PROBA_CLONAGE )
        aAjouter.push_back( clone() );

    //comportement
    if ( _comportement != nullptr )
    {
        std::vector<Bestiole*>& tous = monMilieu.getBestioles();
        // construire la liste des voisins détectés
        std::vector<Bestiole*> voisins;
        for ( Bestiole* other : tous )
            if ( other != this && jeTeVois( *other ) )
                voisins.push_back( other );

        _comportement->action( this, voisins );
    }
    bouge( monMilieu.getWidth(), monMilieu.getHeight() );
}

void Bestiole::ajouterCapteur( ICapteur* c )
{
    capteurs.push_back( c );
}

void Bestiole::ajouterAccessoire( IAccessoire* a )
{
    accessoires.push_back( a );
}

double Bestiole::getVitesseEffective() const
{
    double v = vitesse;

    for ( IAccessoire* a : accessoires )
        v = a->modifierVitesse( v );

    return v;
}

double Bestiole::getCamouflage() const
{
    double camouflage = 0.0;

    for ( IAccessoire* a : accessoires )
        camouflage += a->getBonusCamouflage();

    return camouflage;
}

double Bestiole::getProtectionCollision() const
{
    double protection = 0.0;

    for ( IAccessoire* a : accessoires )
        protection += a->getBonusProtection();

    return protection;
}

bool Bestiole::detecte( const Bestiole & b ) const
{
    if ( capteurs.empty() )
    {
        double dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
        return ( dist <= LIMITE_VUE );
    }

    for ( ICapteur* c : capteurs )
        if ( c->detecte( *this, b ) )
            return true;

    return false;
}

Bestiole* Bestiole::clone() const
{
    return new Bestiole( *this ); 
}