//
// Created by rem on 21/02/18.
//

#include "Vector.h"

Vector::Vector(int x, int y) : x(x), y(y){
    computePolar();
}

Vector::Vector(double ray, double theta) : ray(ray), theta(theta){
    computeCartesian();
}

Vector::Vector(const Vector& vector) {
    this->x = vector.getX();
    this->y = vector.getY();
    computePolar();
}

Vector::Vector() : x(0), y(0){
    computePolar();
}

Vector Vector:: operator+(const Vector& other) const{
    return {this->x + other.x, this->y + other.y};
}

Vector Vector:: operator-(const Vector& other) const{
    return {this->x - other.x, this->y - other.y};
}

int Vector::distanceTo(const Vector &other) const{
    return (int)((*this-other).getRay());
}

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

void Vector::computeCartesian() {
    this->x = (int)(ray*cos(this->theta));
    this->y = (int)(ray*sin(this->theta));
}

int Vector::getX() const {
    return x;
}
void Vector::setX(int x) {
    Vector::x = x;
    computePolar();
}
int Vector::getY() const {
    return y;
}
void Vector::setY(int y) {
    Vector::y = y;
    computePolar();
}
double Vector::getRay() const {
    return ray;
}
void Vector::setRay(double ray) {
    Vector::ray = ray;
    computeCartesian();
}
double Vector::getTheta() const {
    return theta;
}
void Vector::setTheta(double theta) {
    Vector::theta = theta;
    computeCartesian();
}
