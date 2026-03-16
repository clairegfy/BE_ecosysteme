#include "Nageoires.h"

Nageoires::Nageoires(double f)
{
    facteur = f;
}

double Nageoires::modifierVitesse(double vitesseBase) const
{
    return vitesseBase * facteur;
}