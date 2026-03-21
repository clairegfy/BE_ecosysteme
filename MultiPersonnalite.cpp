#include "MultiPersonnalite.h"
#include <cstdlib>

MultiPersonnalite::MultiPersonnalite() : _courant(0), _timer(0) {}

MultiPersonnalite::~MultiPersonnalite()
{
    for ( Comportement* c : _strategies )
        delete c;
}

void MultiPersonnalite::ajouterComportement( Comportement* c )
{
    _strategies.push_back( c );
}

void MultiPersonnalite::action( Bestiole* b, std::vector<Bestiole*>& voisins )
{
    if ( _strategies.empty() ) return;

    // change de personnalité après DUREE pas
    if ( ++_timer >= DUREE )
    {
        _timer = 0;
        _courant = rand() % _strategies.size();
    }
    _strategies[ _courant ]->action( b, voisins );
}

Comportement* MultiPersonnalite::clone() const
{
    MultiPersonnalite* mp = new MultiPersonnalite();
    for ( Comportement* c : _strategies )
        mp->ajouterComportement( c->clone() );
    mp->_courant = _courant;
    mp->_timer   = _timer;
    return mp;
}

void MultiPersonnalite::getCouleur(unsigned char & r, unsigned char & g, unsigned char & b) const {
    _strategies[_courant]->getCouleur(r, g, b);
}