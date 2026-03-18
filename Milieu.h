#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "SimMemento.h"
#include "EvenementObserver.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Milieu : public UImg, public EvenementObserver
{

private :
   static const T          white[];

    int                     width, height;
    std::vector<Bestiole*> listeBestioles;
    static const double SEUIL_COLLISION;
    SimMemento memento;

public :
   Milieu( int _width, int _height );
    ~Milieu( void );

    int getWidth( void ) const { return width; };
    int getHeight( void ) const { return height; };

    void step( void );

    void addMember( Bestiole* b );
    void removeMember( Bestiole* b );
    int nbVoisins( Bestiole* b );
    std::vector<Bestiole*>& getBestioles(){ return listeBestioles; };
    SimMemento& getMemento() { return memento; }

    void notifier( const EvenementSim& e ) override;
};


#endif