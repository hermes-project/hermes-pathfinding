//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_LANDMARK_H
#define HERMES_PATHFINDING_LANDMARK_H

#define AVERAGE_RAY 50
#define STD_DEVIATION_RAY 10
#define AVERAGE_ADDED_OBSTACLE 10
#define STD_DEVIATION_ADDED_OBSTACLE 5

#include <vector>
#include <random>
#include "Node.h"
#include "../smartMaths/Circle.h"

class Landmark {
public:
    /** Constructeur & Destructeur */
    Landmark(int size_X, int size_Y, int nb_obstalce);

    /** Ré-initialise les obstacles */
    void reInitObstacle();

    /** Ajoute des obstacles */
    void addObstacle();
    bool isInObstacle(const Vector& vector);
    bool isInLandmark(const Vector& vector);

    /** Getters & Setters */
    int getSize_X() const;
    int getSize_Y() const;
    std::vector<Circle> &getListStaticObstacle();

private:
    int size_X;
    int size_Y;
    int init_nb_Obstacle;
    std::vector<Circle> listStaticObstacle;

    /** Initialise des obstacles de taille random */
    void initObstacle();
};

#endif //HERMES_PATHFINDING_LANDMARK_H