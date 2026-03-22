#include "PopulationConfig.h"

PopulationConfig::PopulationConfig( int g, int p, int k, int pr, int m )
{
    nbGregaires = g;
    nbPeureuses = p;
    nbKamikazes = k;
    nbPrevoyantes = pr;
    nbMulti = m;
}

int PopulationConfig::getNbGregaires() const
{
    return nbGregaires;
}

int PopulationConfig::getNbPeureuses() const
{
    return nbPeureuses;
}

int PopulationConfig::getNbKamikazes() const
{
    return nbKamikazes;
}

int PopulationConfig::getNbPrevoyantes() const
{
    return nbPrevoyantes;
}

int PopulationConfig::getNbMulti() const
{
    return nbMulti;
}