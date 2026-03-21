#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "Comportement.h"

class Peureuse : public Comportement
{
private :
    static const int    SEUIL_PEUR = 3;    // nb voisins déclenchant la fuite
    static const double VITESSE_FUITE;
    static const double VITESSE_CROISIERE;
    bool                _enFuite;
public :
    Peureuse() : _enFuite(false) {}
    void action( Bestiole* b, std::vector<Bestiole*>& voisins ) override;
    Comportement* clone() const override { return new Peureuse(*this); }

    void getCouleur(unsigned char & r, unsigned char & g, unsigned char & b) const override;
};

#endif