#include "Camouflage.h"

Camouflage::Camouflage(double p)
{
    psi = p;
}

double Camouflage::getBonusCamouflage() const
{
    return psi;
}

double Camouflage::modifierVitesse(double vitesseBase) const
{
    return vitesseBase;
}

double Camouflage::getBonusProtection() const
{
    return 0.0;
}

