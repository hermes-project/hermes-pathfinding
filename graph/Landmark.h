//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_LANDMARK_H
#define HERMES_PATHFINDING_LANDMARK_H

using namespace std;

#include <vector>
#include <QtGui/QPaintEvent>
#include <QtWidgets/QFrame>
#include "../smartMaths/Ellipse.h"
#include "Node.h"
#include "../smartMaths/Circle.h"

class Landmark : public QFrame{
public:
    /** Constructeur */
    Landmark(int size_X, int size_Y, int nb_obstalce);

    /** Getters & Setters */
    int getSize_X() const;
    int getSize_Y() const;

private:
    int size_X;
    int size_Y;
    vector<Circle> listStaticObstacle;

    /** Initialise des obstacles de taille random */
    void initObstacle(int nb_obstacle);
    bool isInObstacle(const Vector& vector);
    bool isInLandmark(const Vector& vector);

    /** Methode qui dessine */
    void paintEvent(QPaintEvent* event);
    Vector displayRef(Vector vec);
};

#endif //HERMES_PATHFINDING_LANDMARK_H