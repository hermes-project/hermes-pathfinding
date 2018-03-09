//
// Created by rem on 09/03/18.
//

#ifndef HERMES_PATHFINDING_CIRCLE_H
#define HERMES_PATHFINDING_CIRCLE_H

#include "Ellipse.h"
#include "Vector.h"

class Circle : public Ellipse{
public:
    /** Constructeur */
    Circle(Vector center, int ray);
};


#endif //HERMES_PATHFINDING_CIRCLE_H
