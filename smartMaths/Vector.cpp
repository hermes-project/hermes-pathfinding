//
// Created by rem on 21/02/18.
//

#include <cmath>
#include <algorithm>
#include "Vector.h"

/** Constructeur en coordonnées cartésiennes */
Vector::Vector(int x, int y){
    this->x=x;
    this->y=y;
    computePolar();
}

/** Constructeur en coordonnées polaires */
Vector::Vector(double ray, double theta){
    this->ray=ray;
    this->theta=theta;
    computeCartesian();
}

/** Retourne un nouvel objet de type vecteur, somme des deux vecteurs */
Vector Vector:: operator+(Vector& other){
    return Vector(this->x + other.x, this->y + other.y);
}

/** Retourne un nouvel objet de type vecteur, soustraction des deux vecteurs */
Vector Vector:: operator-(Vector& other){
    return Vector(this->x - other.x, this->y - other.y);
}

/** Calcul des coordonnées polaires à partir des cartéiennes */
void Vector::computePolar() {
    this->ray=sqrt(this->x*this->x + this->y*this->y);

    // Développement limité
    double ratio = (double)std::min(this->x, this->y)/std::max(this->x, this->y);
    double squaredRatio = pow(ratio,2);
    double noOffsetAngle = ((-0.0464964749 * squaredRatio + 0.15931422) * squaredRatio - 0.327622764) * squaredRatio * ratio + ratio;

    // Offset
    if (abs(y) > abs(x))
        noOffsetAngle = 1.57079637 - noOffsetAngle;
    if (x < 0)
        noOffsetAngle = 3.14159274 - noOffsetAngle;
    if (y < 0)
        noOffsetAngle = -noOffsetAngle;

    if(this->ray == 0){
        this->theta = 0;
    }else{
        this->theta = noOffsetAngle;
    }
}

/** Calcul des coordonnées cartésiennes à partir des polaires */
void Vector::computeCartesian() {
    this->x = (int)(ray*cos(this->theta));
    this->y = (int)(ray*sin(this->theta));
}

/** Getters & Setters */
int Vector::getX() const {
    return x;
}
void Vector::setX(int x) {
    Vector::x = x;
}
int Vector::getY() const {
    return y;
}
void Vector::setY(int y) {
    Vector::y = y;
}
double Vector::getRay() const {
    return ray;
}
void Vector::setRay(double ray) {
    Vector::ray = ray;
}
double Vector::getTheta() const {
    return theta;
}
void Vector::setTheta(double theta) {
    Vector::theta = theta;
}
