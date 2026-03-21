#include "Kamikaze.h"
#include "Bestiole.h"
#include <cmath>
#include <limits>

void Kamikaze::action( Bestiole* b, std::vector<Bestiole*>& voisins )
{
    if ( voisins.empty() ) return;

    // cherche le voisin le plus proche
    Bestiole* cible = nullptr;
    double distMin = std::numeric_limits<double>::max();
    for ( Bestiole* v : voisins )
    {
        double dist = std::sqrt(
            (b->getX() - v->getX()) * (b->getX() - v->getX()) +
            (b->getY() - v->getY()) * (b->getY() - v->getY())
        );
        if ( dist < distMin ) { distMin = dist; cible = v; }
    }

    // oriente vers la cible
    if ( cible != nullptr )
    {
        double dx = cible->getX() - b->getX();
        double dy = cible->getY() - b->getY();
        b->setOrientation( atan2( -dy, dx ) );  // -dy car axe y inversé
    }
}

void Kamikaze::getCouleur(unsigned char & r, unsigned char & g, unsigned char & b) const {
    r = 255; g = 0; b = 0; 
}