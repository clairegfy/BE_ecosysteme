#include "Aquarium.h"
#include "Milieu.h"
#include "BestiolesFactory.h"
#include "PopulationConfig.h"

int main()
{
    Aquarium ecosysteme( 640, 480, 30 );

    // configuration de la population
    PopulationConfig config( 5, 5, 5, 5, 5 );  // grégaires, peureuses, kamikazes, prévoyantes, multi

    // factory — point d'entrée unique
    BestiolesFactory* factory = BestiolesFactory::getInstance();

    // main fait le lien factory milieu
    for ( Bestiole* b : factory->creerPopulation( config ) )
        ecosysteme.getMilieu().addMember( b );

    ecosysteme.run();
    return 0;
}
