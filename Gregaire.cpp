#include "Gregaire.h"
#include "Bestiole.h"
#include <cmath>

void Gregaire::action( Bestiole* b, std::vector<Bestiole*>& voisins )
{
    if ( voisins.empty() ) return;

    // calcule la direction moyenne des voisins
    double sommeX = 0., sommeY = 0.;
    for ( Bestiole* v : voisins )
    {
        sommeX += cos( v->getOrientation() );
        sommeY += sin( v->getOrientation() );
    }
    b->setOrientation( atan2( sommeY / voisins.size(),
                               sommeX / voisins.size() ) );
}
void Gregaire::getCouleur(unsigned char & r, unsigned char & g, unsigned char & b) const {
    r = 0;   
    g = 255; 
    b = 0;   
}