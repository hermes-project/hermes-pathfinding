//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_LANDMARK_H
#define HERMES_PATHFINDING_LANDMARK_H

#define AVERAGE_RAY 50
#define STD_DEVIATION 10

#include <vector>
#include "Node.h"
#include "../smartMaths/Circle.h"

class Landmark {
public:
    /** Constructeur */
    Landmark(int size_X, int size_Y, int nb_obstalce);

    /** Getters & Setters */
    int getSize_X() const;
    int getSize_Y() const;
    const std::vector<Circle> &getListStaticObstacle() const;

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