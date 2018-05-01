//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_LANDMARK_H
#define HERMES_PATHFINDING_LANDMARK_H

#define AVERAGE_RAY 70
#define STD_DEVIATION_RAY 15
#define AVERAGE_ADDED_OBSTACLE 10
#define STD_DEVIATION_ADDED_OBSTACLE 5

#include <vector>
#include <random>
#include "Node.h"
#include "../smartMaths/Circle.h"
#include "../smartMaths/maths_lib.h"
#include "../utils/Log.h"

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
    bool intersectAnyObstacle(const Vector& vector0, const Vector& vector1);

    /** Getters & Setters */
    int getSize_X() const;
    int getSize_Y() const;
    std::vector<Circle> &getListStaticObstacle();
    const Vector &getUL() const;
    const Vector &getUR() const;
    const Vector &getDL() const;
    const Vector &getDR() const;

private:
    Log* log;
    int size_X;
    int size_Y;
    int init_nb_Obstacle;
    std::vector<Circle> listStaticObstacle;
    std::default_random_engine generator;
    Vector UL;
    Vector UR;
    Vector DL;
    Vector DR;

    /** Initialise des obstacles de taille random */
    void initObstacle();
};

#endif //HERMES_PATHFINDING_LANDMARK_H