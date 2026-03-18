#include "SimulationAnalyser.h"
#include <iostream>
#include <algorithm>

void SimulationAnalyser::afficherBilan( const SimMemento& memento )
{
    const std::vector<int>& data = memento.getHistorique();

    std::cout << std::endl;
    std::cout << "=== Bilan simulation ===" << std::endl;

    if ( data.empty() )
    {
        std::cout << "Aucune donnee enregistree." << std::endl;
        return;
    }

    int debut = data.front();
    int fin = data.back();
    int minimum = *std::min_element( data.begin(), data.end() );
    int maximum = *std::max_element( data.begin(), data.end() );

    std::cout << "Nombre d'etats enregistres : " << data.size() << std::endl;
    std::cout << "Population debut : " << debut << std::endl;
    std::cout << "Population fin   : " << fin << std::endl;
    std::cout << "Population min   : " << minimum << std::endl;
    std::cout << "Population max   : " << maximum << std::endl;
}