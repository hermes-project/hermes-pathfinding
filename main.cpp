#include <iostream>
#include "smartMaths/Vector.h"
#include "smartMaths/Circle.h"

// Pour le moment c'est un foure-tout pour les tests, histoire de bien apprendre le C++
int main() {
    Vector vec(50,0);
    Vector* vec0 = new Vector(100, 100);
    std::cout<<"Somme des deux vecteurs : "<< (vec+*vec0).getX() << "," << (vec+*vec0).getY() << "\n";

    Circle cir(vec, 500);
    Circle* circle = new Circle(*vec0, 200);
    std::cout<<"Circle cir : "<< (cir.getCenter().getX()) << "," << (cir.getCenter().getY()) << ", ray :" << cir.getRay() << "\n";
    std::cout<<"Circle circle : "<< ((*circle).getCenter().getX()) << "," << ((*circle).getCenter().getY()) << ", ray :" << (*circle).getRay() << "\n";

    delete vec0;
    delete circle;
    return 0;
}