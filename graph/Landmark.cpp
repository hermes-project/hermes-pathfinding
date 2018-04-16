//
// Created by rem on 20/03/18.
//

#include <random>
#include "Landmark.h"

Landmark::Landmark(int size_X, int size_Y, int nb_obstacle) : size_X(size_X), size_Y(size_Y){
    srand(time(NULL));
    initObstacle(nb_obstacle);
}

void Landmark::initObstacle(int nb_obstacle) {
    std::default_random_engine generator;
    std::normal_distribution<float> ray(AVERAGE_RAY, STD_DEVIATION);
    for (int i=0; i<nb_obstacle; i++){
        int posX = rand()%(size_X - AVERAGE_RAY) - size_X/2 + AVERAGE_RAY/2;
        int posY = rand()%(size_Y - AVERAGE_RAY) - size_Y/2 + AVERAGE_RAY/2;
        listStaticObstacle.emplace_back(Circle(Vector(posX, posY), (int)ray(generator)));
    }
}

bool Landmark::isInObstacle(const Vector& vector){
    std::vector<Circle>::iterator it;
    for (it = listStaticObstacle.begin(); it != listStaticObstacle.end(); it++){
        if((vector-it->getCenter()).getRay() < it->getWidth()/2){
            return true;
        }
    }
    return false;
}

bool Landmark::isInLandmark(const Vector &vector) {
    return abs(vector.getX()) < size_X/2 && abs(vector.getY()) <size_Y/2;
}

int Landmark::getSize_X() const {
    return size_X;
}

int Landmark::getSize_Y() const {
    return size_Y;
}

const std::vector<Circle> &Landmark::getListStaticObstacle() const {
    return listStaticObstacle;
}
