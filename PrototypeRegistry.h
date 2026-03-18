#ifndef _PROTOTYPEREGISTRY_H_
#define _PROTOTYPEREGISTRY_H_

#include "Bestiole.h"
#include <map>
#include <string>

using namespace std;

class PrototypeRegistry
{
private:
    map<string, Bestiole*> prototypes;

public:
    PrototypeRegistry();
    ~PrototypeRegistry();

    void enregistrerPrototype( const string& nom, Bestiole* b );
    Bestiole* cloner( const string& nom ) const;
};

#endif