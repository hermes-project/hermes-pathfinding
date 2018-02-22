#include <iostream>
#include "smartMaths/Vector.h"

int main() {
    Vector vec(50,0);
    Vector* vec0 = new Vector(100, 100);
    std::cout<<"Somme des deux vecteurs : "<< (vec+*vec0).getX() << "," << (vec+*vec0).getY();
    delete vec0;
    return 0;
}