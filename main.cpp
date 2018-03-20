#include <iostream>
#include "smartMaths/Vector.h"
#include "graph/Node.h"

// Pour le moment c'est un foure-tout pour les tests, histoire de bien apprendre le C++
int main(int argc, char** argv) {

    Vector vec(50,0);
    Vector* vec0 = new Vector(100, 100);
    std::cout<<"Somme des deux vecteurs : "<< (vec+*vec0).getX() << "," << (vec+*vec0).getY() << "\n";

    Node node(50, 200);

    delete vec0;
    return 0;
}