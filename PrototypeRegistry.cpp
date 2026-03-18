#include "PrototypeRegistry.h"

PrototypeRegistry::PrototypeRegistry()
{
}

PrototypeRegistry::~PrototypeRegistry()
{
    for ( auto& p : prototypes )
        delete p.second;
}

void PrototypeRegistry::enregistrerPrototype( const string& nom, Bestiole* b )
{
    if ( prototypes.find( nom ) != prototypes.end() )
        delete prototypes[nom];

    prototypes[nom] = b;
}

Bestiole* PrototypeRegistry::cloner( const string& nom ) const
{
    auto it = prototypes.find( nom );

    if ( it == prototypes.end() )
        return nullptr;

    return new Bestiole( *(it->second) );
}