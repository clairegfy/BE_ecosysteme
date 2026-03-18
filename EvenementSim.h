#ifndef _EVENEMENTSIM_H_
#define _EVENEMENTSIM_H_

enum TypeEvenement
{
    NAISSANCE,
    MORT,
    CHANGEMENT_COMPORTEMENT
};

struct EvenementSim
{
    TypeEvenement type;

    EvenementSim( TypeEvenement t ) : type( t ) {}
};

#endif