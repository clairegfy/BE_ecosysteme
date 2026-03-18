#ifndef _POPULATIONCONFIG_H_
#define _POPULATIONCONFIG_H_

class PopulationConfig
{
private:
    int nbGregaires;
    int nbPeureuses;
    int nbKamikazes;
    int nbMulti;

public:
    PopulationConfig( int g = 5, int p = 5, int k = 5, int m = 5 );

    int getNbGregaires() const;
    int getNbPeureuses() const;
    int getNbKamikazes() const;
    int getNbMulti() const;
};

#endif