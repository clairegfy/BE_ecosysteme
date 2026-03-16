#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "MultiPersonnalite.h"
#include "Yeux.h"
#include "Oreilles.h"
#include "Nageoires.h"
#include "Carapace.h"
#include "Camouflage.h"

int main()
{
    Aquarium ecosysteme( 640, 480, 30 );

    // 5 grégaires
    for ( int i = 0; i < 5; ++i ) {
        Bestiole* b = new Bestiole();
        b->setComportement( new Gregaire() );
        b->ajouterCapteur( new Yeux(1.5, 60.0, 1.0) );
        b->ajouterAccessoire( new Nageoires(1.3) );
        ecosysteme.getMilieu().addMember( b );
    }

    // 5 peureuses
    for ( int i = 0; i < 5; ++i ) {
        Bestiole* b = new Bestiole();
        b->setComportement( new Peureuse() );
        b->ajouterCapteur( new Oreilles(50.0, 1.0) );
        b->ajouterAccessoire( new Camouflage(0.5) );
        ecosysteme.getMilieu().addMember( b );
    }

    // 5 kamikazes
    for ( int i = 0; i < 5; ++i ) {
        Bestiole* b = new Bestiole();
        b->setComportement( new Kamikaze() );
        b->ajouterCapteur( new Yeux(1.2, 70.0, 1.0) );
        b->ajouterAccessoire( new Carapace(0.3, 0.8) );
        ecosysteme.getMilieu().addMember( b );
    }

    // 5 multi-personnalités
    for ( int i = 0; i < 5; ++i ) {
        Bestiole* b = new Bestiole();
        MultiPersonnalite* mp = new MultiPersonnalite();
        mp->ajouterComportement( new Gregaire() );
        mp->ajouterComportement( new Kamikaze() );
        b->setComportement( mp );
        b->ajouterCapteur( new Yeux(1.5, 60.0, 1.0) );
        b->ajouterCapteur( new Oreilles(40.0, 1.0) );
        ecosysteme.getMilieu().addMember( b );
    }

    ecosysteme.run();
    return 0;
}