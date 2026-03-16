#include "Oreilles.h"
#include "Bestiole.h"
#include <cmath>

Oreilles::Oreilles(double d, double g)
{
    distance = d;
    gamma = g;
}

bool Oreilles::detecte(const Bestiole& self, const Bestiole& other) const
{
    double dx = other.getX() - self.getX();
    double dy = other.getY() - self.getY();

    double dist = std::sqrt(dx * dx + dy * dy);

    if (dist > distance)
        return false;

    return true;
}