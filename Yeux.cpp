#include "Yeux.h"
#include "Bestiole.h"
#include <cmath>

Yeux::Yeux(double a, double d, double g)
{
    alpha = a;
    distance = d;
    gamma = g;
}

bool Yeux::detecte(const Bestiole& self, const Bestiole& other) const
{
    double dx = other.getX() - self.getX();
    double dy = other.getY() - self.getY();

    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist > distance)
        return false;

    double angle = std::atan2(-dy, dx);
    double diff = std::fabs(angle - self.getOrientation());

    if (diff > M_PI)
        diff = 2 * M_PI - diff;

    if (diff > alpha / 2.0)
        return false;

    return true;
}