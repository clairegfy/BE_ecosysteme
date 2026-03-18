#ifndef _EVENEMENTOBSERVER_H_
#define _EVENEMENTOBSERVER_H_

#include "EvenementSim.h"

class EvenementObserver
{
public:
    virtual void notifier( const EvenementSim& e ) = 0;
    virtual ~EvenementObserver() {}
};

#endif