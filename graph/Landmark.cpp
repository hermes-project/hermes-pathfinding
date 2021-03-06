//
// Created by rem on 20/03/18.
//

#include "Landmark.h"

Landmark::Landmark(int size_X, int size_Y, int nb_obstacle) :
        size_X(size_X),
        size_Y(size_Y),
        init_nb_Obstacle(nb_obstacle),
        log(Log::getInstance())
{
    generator.seed(time(NULL));
    initObstacle();
    UL = Vector(-size_X/2, size_Y/2);
    UR = Vector(size_X/2, size_Y/2);
    DL = Vector(-size_X/2, -size_Y/2);
    DR = Vector(size_X/2, -size_Y/2);
}

void Landmark::initObstacle() {
    std::normal_distribution<float> ray(AVERAGE_RAY, STD_DEVIATION_RAY);
    std::uniform_int_distribution<int> pos;
    for (int i=0; i<init_nb_Obstacle; i++){
        int posX = pos(generator)%(size_X - AVERAGE_RAY) - size_X/2 + AVERAGE_RAY;
        int posY = pos(generator)%(size_Y - AVERAGE_RAY) - size_Y/2 + AVERAGE_RAY;
        listStaticObstacle.emplace_back(Vector(posX, posY), (int)ray(generator));
    }
}

void Landmark::reInitObstacle() {
    listStaticObstacle.clear();
    initObstacle();
}

void Landmark::addObstacle() {
    std::normal_distribution<float> ray(AVERAGE_RAY, STD_DEVIATION_RAY);
    std::normal_distribution<float> nb_Obstacle(AVERAGE_ADDED_OBSTACLE, STD_DEVIATION_ADDED_OBSTACLE);
    std::uniform_int_distribution<int> pos;
    int nb = (int) nb_Obstacle(generator);
    for (int i=0; i<nb; i++){
        int posX = pos(generator)%(size_X - AVERAGE_RAY) - size_X/2 + AVERAGE_RAY;
        int posY = pos(generator)%(size_Y - AVERAGE_RAY) - size_Y/2 + AVERAGE_RAY;
        listStaticObstacle.emplace_back(Vector(posX, posY), (int)ray(generator));
    }
    log->debug(std::to_string(nb) + " obstacles added, (total " + std::to_string(listStaticObstacle.size()) + ")");
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

bool Landmark::intersectAnyObstacle(const Vector &vector0, const Vector &vector1) {
    std::vector<Circle>::iterator obstacle;
    for (obstacle = listStaticObstacle.begin(); obstacle != listStaticObstacle.end(); obstacle++){
        if (intersect(vector0, vector1, *obstacle)){
            return true;
        }
    }
    return false;
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

const Vector &Landmark::getUL() const {
    return UL;
}

const Vector &Landmark::getUR() const {
    return UR;
}

const Vector &Landmark::getDL() const {
    return DL;
}

const Vector &Landmark::getDR() const {
    return DR;
}
