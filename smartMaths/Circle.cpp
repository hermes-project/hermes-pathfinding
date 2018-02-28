//
// Created by rem on 28/02/18.
//

#include "Circle.h"

/** Constructeur */
Circle::Circle(Vector center, int ray){
    this->center = center;
    this->ray = ray;
}

/** Getters & Setters */
const Vector &Circle::getCenter() const {
    return center;
}
void Circle::setCenter(const Vector &center) {
    Circle::center = center;
}
int Circle::getRay() const {
    return ray;
}
void Circle::setRay(int ray) {
    Circle::ray = ray;
}
