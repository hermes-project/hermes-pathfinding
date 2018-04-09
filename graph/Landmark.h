//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_LANDMARK_H
#define HERMES_PATHFINDING_LANDMARK_H

#include <vector>
#include <QtGui/QPaintEvent>
#include <QtWidgets/QFrame>
#include "../smartMaths/Ellipse.h"
#include "Node.h"
#include "../smartMaths/Circle.h"

class Landmark {
public:
    /** Constructeur */
    Landmark(int size_X, int size_Y, int nb_obstalce);

    /** Getters & Setters */
    int getSize_X() const;
    int getSize_Y() const;

private:
    int size_X;
    int size_Y;
    std::vector<Circle> listStaticObstacle;

    /** Initialise des obstacles de taille random */
    void initObstacle(int nb_obstacle);
    bool isInObstacle(const Vector& vector);
    bool isInLandmark(const Vector& vector);

};

#endif //HERMES_PATHFINDING_LANDMARK_H