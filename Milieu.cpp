#include "Milieu.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

const T      Milieu::white[]          = { (T)255, (T)255, (T)255 };
const double Milieu::SEUIL_COLLISION  = 8.0;

Milieu::Milieu( int _width, int _height )
    : UImg( _width, _height, 1, 3 ), width(_width), height(_height)
{
    cout << "const Milieu" << endl;
    std::srand( time(NULL) );
}

Milieu::~Milieu( void )
{
    for ( Bestiole* b : listeBestioles )
        delete b;
    listeBestioles.clear();
    cout << "dest Milieu" << endl;
}

void Milieu::addMember( Bestiole* b )
{
    b->initCoords( width, height );
    listeBestioles.push_back( b );
}

void Milieu::removeMember( Bestiole* b )
{
    auto it = std::find( listeBestioles.begin(), listeBestioles.end(), b );
    if ( it != listeBestioles.end() )
    {
        delete *it;
        listeBestioles.erase( it );
    }
}

void Milieu::notifier( const EvenementSim& e )
{
    if ( e.type == NAISSANCE )
    {
        Bestiole* b = new Bestiole();

        int tirage = std::rand() % 3;
        if ( tirage == 0 )
            b->setComportement( new Gregaire() );
        else if ( tirage == 1 )
            b->setComportement( new Peureuse() );
        else
            b->setComportement( new Kamikaze() );

        addMember( b );
    }

    else if ( e.type == MORT )
    {
        if ( !listeBestioles.empty() )
        {
            int index = std::rand() % listeBestioles.size();
            removeMember( listeBestioles[index] );
        }
    }

    else if ( e.type == CHANGEMENT_COMPORTEMENT )
    {
        if ( !listeBestioles.empty() )
        {
            int index = std::rand() % listeBestioles.size();
            Bestiole* b = listeBestioles[index];

            int tirage = std::rand() % 3;
            if ( tirage == 0 )
                b->setComportement( new Gregaire() );
            else if ( tirage == 1 )
                b->setComportement( new Peureuse() );
            else
                b->setComportement( new Kamikaze() );
        }
    }
}

void Milieu::step( void )
{
    cimg_forXY( *this, px, py )
        fillC( px, py, 0, white[0], white[1], white[2] );

    std::vector<Bestiole*> aMourir;
    for ( Bestiole* b : listeBestioles )
        if ( b->estMort() )
            aMourir.push_back( b );

    for ( int i = 0; i < (int)listeBestioles.size(); ++i )
    {
        for ( int j = i+1; j < (int)listeBestioles.size(); ++j )
        {
            Bestiole* b1 = listeBestioles[i];
            Bestiole* b2 = listeBestioles[j];

            double dist = std::sqrt(
                (double)(b1->getX() - b2->getX()) * (b1->getX() - b2->getX()) +
                (double)(b1->getY() - b2->getY()) * (b1->getY() - b2->getY())
            );

            if ( dist < SEUIL_COLLISION )
            {
                double proba = static_cast<double>( std::rand() ) / RAND_MAX;

                double probaMortB1 = 0.2 * ( 1.0 - b1->getProtectionCollision() );
                double probaMortB2 = 0.2 * ( 1.0 - b2->getProtectionCollision() );

                Bestiole* victime = ( std::rand() % 2 == 0 ) ? b1 : b2;
                double probaMort = ( victime == b1 ) ? probaMortB1 : probaMortB2;

                if ( proba < probaMort )
                {
                    if ( std::find( aMourir.begin(), aMourir.end(), victime )
                         == aMourir.end() )
                        aMourir.push_back( victime );
                }
                else
                {
                    b1->setOrientation( b1->getOrientation() + M_PI );
                    b2->setOrientation( b2->getOrientation() + M_PI );
                }
            }
        }
    }

    for ( Bestiole* b : aMourir )
        removeMember( b );

    for ( Bestiole* b : listeBestioles )
    {
        b->action( *this );
        b->draw( *this );
    }

    memento.save( listeBestioles.size() );
}

int Milieu::nbVoisins( Bestiole* b )
{
    int nb = 0;
    for ( Bestiole* other : listeBestioles )
        if ( other != b && b->jeTeVois( *other ) )
            ++nb;
    return nb;
}