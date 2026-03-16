#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "ICapteur.h"

class Oreilles : public ICapteur
{
private:
    double distance;
    double gamma;

public:
    Oreilles(double d, double g);

    bool detecte(const Bestiole& self, const Bestiole& other) const override;

    ICapteur* clone() const override { return new Oreilles(*this); }
};

#endif