//
// Created by rem on 28/02/18.
//

#ifndef HERMES_PATHFINDING_CIRCLE_H
#define HERMES_PATHFINDING_CIRCLE_H

#include "Vector.h"

class Circle {
public:
    /** Constructeur */
    Circle(Vector center, int ray);

    /** Getters, Setters & useful */
    Circle clone();
    const Vector &getCenter() const;
    void setCenter(const Vector &center);
    int getRay() const;
    void setRay(int ray);

private:
    /** Paramètres */
    Vector center;
    int ray;
};


#endif //HERMES_PATHFINDING_CIRCLE_H
