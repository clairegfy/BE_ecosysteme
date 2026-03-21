#ifndef _MULTIPERSONNALITE_H_
#define _MULTIPERSONNALITE_H_

#include "Comportement.h"
#include <vector>

class MultiPersonnalite : public Comportement
{
private :
    std::vector<Comportement*>  _strategies;
    int                         _courant;
    int                         _timer;
    static const int            DUREE = 50;  // pas avant changement

public :
    MultiPersonnalite();
    ~MultiPersonnalite();
    void ajouterComportement( Comportement* c );
    void action( Bestiole* b, std::vector<Bestiole*>& voisins ) override;
    Comportement* clone() const override;
    void getCouleur(unsigned char & r, unsigned char & g, unsigned char & b) const override;
};

#endif