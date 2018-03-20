//
// Created by rem on 20/03/18.
//

#include <cstdlib>
#include <time.h>
#include <random>
#include "Landmark.h"
#include "../smartMaths/Circle.h"

Landmark::Landmark(int size_X, int size_Y, int nb_obstacle) : size_X(size_X), size_Y(size_Y){
    initObstacle(nb_obstacle);
    srand(time(NULL));
}

void Landmark::initObstacle(int nb_obstacle) {
    for (int i=0; i<nb_obstacle; i++){
        int posX = rand()%size_X - size_X/2;
        int posY = rand()%size_Y - size_Y/2;
        std::default_random_engine generator;
        std::normal_distribution<float> ray(50, 20);
        listStaticObstacle.push_back(Circle(Vector(posX, posY), (int)ray(generator)));
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