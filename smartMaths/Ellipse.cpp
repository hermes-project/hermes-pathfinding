//
// Created by rem on 28/02/18.
//

#include <cmath>
#include "Ellipse.h"

Ellipse::Ellipse(Vector center, int width, int height, double angle) :
        center (center), angle (angle){

    // width doit être la plus grande valeur
    if(height > width){
        int h = height;
        height = width;
        width = h;
    }

    this->width = width;
    this->height = height;

    this->p = width - height*height/(2*width);
    this->e = sqrt(width*width - height*height)/width;
}

const Vector &Ellipse::getCenter() const {
    return center;
}
void Ellipse::setCenter(const Vector &center) {
    Ellipse::center = center;
}
int Ellipse::getWidth() const {
    return width;
}
void Ellipse::setWidth(int width) {
    Ellipse::width = width;
}
int Ellipse::getHeight() const {
    return height;
}
void Ellipse::setHeight(int height) {
    Ellipse::height = height;
}
double Ellipse::getAngle() const {
    return angle;
}
void Ellipse::setAngle(double angle) {
    Ellipse::angle = angle;
}
