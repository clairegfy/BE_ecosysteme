#ifndef _YEUX_H_
#define _YEUX_H_

#include "ICapteur.h"

class Yeux : public ICapteur
{
private:
    double alpha;
    double distance;
    double gamma;

public:
    Yeux(double a, double d, double g);

    bool detecte(const Bestiole& self, const Bestiole& other) const override;
    ICapteur* clone() const override { return new Yeux(*this); }
};

#endif