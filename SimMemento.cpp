#include "SimMemento.h"

void SimMemento::save( int nb )
{
    historiquePopulation.push_back( nb );
}

const std::vector<int>& SimMemento::getHistorique() const
{
    return historiquePopulation;
}