#include <iostream>
#include <QtWidgets/QApplication>
#include "smartMaths/Vector.h"
#include "graph/Node.h"
#include "display/Window.h"

// Pour le moment c'est un foure-tout pour les tests, histoire de bien apprendre le C++
int main(int argc, char** argv) {

    QApplication app(argc, argv);
    Landmark* landmark = new Landmark(1000, 500, 20);
    Window window(NULL, landmark);
    Vector vec(50,0);
    Vector* vec0 = new Vector(100, 100);
    std::cout<<"Somme des deux vecteurs : "<< (vec+*vec0).getX() << "," << (vec+*vec0).getY() << "\n";

    Node node(50, 200);

    window.setWindowTitle("Hermès - PF");
    window.setMinimumSize(landmark->getSize_X(),landmark->getSize_Y());
    window.showMaximized();
    window.show();
    int error=app.exec();

    delete vec0;
    return error;
}