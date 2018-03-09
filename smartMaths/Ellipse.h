//
// Created by rem on 28/02/18.
//

#ifndef HERMES_PATHFINDING_ELLIPSE_H
#define HERMES_PATHFINDING_ELLIPSE_H

#include "Vector.h"

class Ellipse {
public:
    /** Constructeur */
    Ellipse(Vector center, int width, int height, double angle);

    /** Useful */
    Ellipse clone();

    /** Getters & Setters */
    const Vector &getCenter() const;
    void setCenter(const Vector &center);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    double getAngle() const;
    void setAngle(double angle);

private:
    /** Paramètres */
    Vector center;
    int width;
    int height;
    double angle;

    /** Coordonnées polaires pour placer les noeuds */
    double p;
    double e;
};


#endif //HERMES_PATHFINDING_ELLIPSE_H
