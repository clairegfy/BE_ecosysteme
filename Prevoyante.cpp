#include "Prevoyante.h"
#include "Bestiole.h"
#include <cmath>

void Prevoyante::action( Bestiole* b, std::vector<Bestiole*>& voisins )
{
    if ( voisins.empty() ) return;

    for ( Bestiole* v : voisins )
    {
        // position future estimée du voisin
        double futX = v->getX() + cos( v->getOrientation() ) * v->getVitesse() * HORIZON;
        double futY = v->getY() - sin( v->getOrientation() ) * v->getVitesse() * HORIZON;

        // position future de b
        double myFutX = b->getX() + cos( b->getOrientation() ) * b->getVitesse() * HORIZON;
        double myFutY = b->getY() - sin( b->getOrientation() ) * b->getVitesse() * HORIZON;

        double dist = std::sqrt( (myFutX-futX)*(myFutX-futX)
                               + (myFutY-futY)*(myFutY-futY) );

        // si collision probable, dévier perpendiculairement
        if ( dist < 20. )
            b->setOrientation( b->getOrientation() + M_PI / 2. );
    }
}

void Prevoyante::getCouleur(unsigned char & r, unsigned char & g, unsigned char & b) const {
    r = 255; g = 255; b = 255; 
}