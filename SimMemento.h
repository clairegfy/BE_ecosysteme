#ifndef _SIMMEMENTO_H_
#define _SIMMEMENTO_H_

#include <vector>

class SimMemento
{
private:
    std::vector<int> historiquePopulation;

public:
    void save( int nb );
    const std::vector<int>& getHistorique() const;
};

#endif