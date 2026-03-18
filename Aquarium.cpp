#include "Aquarium.h"

#include "Milieu.h"
#include "EvenementSim.h"
#include "SimulationAnalyser.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

    int         screenWidth = 1280;
    int         screenHeight = 1024;


    cout << "const Aquarium" << endl;

    flotte = new Milieu( width, height );
    assign( *flotte, "Simulation d'ecosysteme" );

    move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

    delete flotte;

    cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{

    cout << "running Aquarium" << endl;

    flotte->getMemento().save( flotte->getBestioles().size() );

    while ( ! is_closed() )
    {
        if ( is_key() ) {
            cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
            cout << " (" << key() << ")" << endl;

            if ( is_keyESC() ) close();
            else if ( key() == 'n' || key() == 'N' )
                flotte->notifier( EvenementSim( NAISSANCE ) );
            else if ( key() == 'm' || key() == 'M' )
                flotte->notifier( EvenementSim( MORT ) );
            else if ( key() == 'c' || key() == 'C' )
                flotte->notifier( EvenementSim( CHANGEMENT_COMPORTEMENT ) );
        }

        flotte->step();
        display( *flotte );

        wait( delay );

    }

    SimulationAnalyser::afficherBilan( flotte->getMemento() );
}
