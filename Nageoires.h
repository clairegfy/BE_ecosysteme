#ifndef _NAGEOIRES_H_
#define _NAGEOIRES_H_

#include "IAccessoire.h"

class Nageoires : public IAccessoire
{
private:
    double facteur;

public:
    Nageoires(double f);

    double modifierVitesse(double vitesseBase) const override;
    IAccessoire* clone() const override { return new Nageoires(*this); }
};

#endif