#include "PopulationConfig.h"

PopulationConfig::PopulationConfig( int g, int p, int k, int m )
{
    nbGregaires = g;
    nbPeureuses = p;
    nbKamikazes = k;
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

int PopulationConfig::getNbMulti() const
{
    return nbMulti;
}