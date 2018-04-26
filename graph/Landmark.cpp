//
// Created by rem on 20/03/18.
//

#include "Landmark.h"

Landmark::Landmark(int size_X, int size_Y, int nb_obstacle) : size_X(size_X), size_Y(size_Y), init_nb_Obstacle(nb_obstacle){
    srand(time(NULL));
    initObstacle();
}

void Landmark::initObstacle() {
    std::default_random_engine generator;
    std::normal_distribution<float> ray(AVERAGE_RAY, STD_DEVIATION_RAY);
    for (int i=0; i<init_nb_Obstacle; i++){
        int posX = rand()%(size_X - AVERAGE_RAY) - size_X/2 + AVERAGE_RAY;
        int posY = rand()%(size_Y - AVERAGE_RAY) - size_Y/2 + AVERAGE_RAY;
        listStaticObstacle.emplace_back(Vector(posX, posY), (int)ray(generator));
    }
}

void Landmark::reInitObstacle() {
    listStaticObstacle.clear();
    initObstacle();
}

void Landmark::addObstacle() {
    std::default_random_engine generator;
    std::normal_distribution<float> ray(AVERAGE_RAY, STD_DEVIATION_RAY);
    std::normal_distribution<float> nb_Obstacle(AVERAGE_ADDED_OBSTACLE, STD_DEVIATION_ADDED_OBSTACLE);
    for (int i=0; i<(int)nb_Obstacle(generator); i++){
        int posX = rand()%(size_X - AVERAGE_RAY) - size_X/2 + AVERAGE_RAY;
        int posY = rand()%(size_Y - AVERAGE_RAY) - size_Y/2 + AVERAGE_RAY;
        listStaticObstacle.emplace_back(Vector(posX, posY), (int)ray(generator));
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

std::vector<Circle> &Landmark::getListStaticObstacle() {
    return listStaticObstacle;
}
