#include <QtWidgets/QApplication>
#include "display/Window.h"

// Pour le moment c'est un foure-tout pour les tests, histoire de bien apprendre le C++
// Pour faire le liens entre la partie fonctionnelle et la partie affichage, voir la classe LandmarkFrame
int main(int argc, char** argv) {

    QApplication app(argc, argv);
    Window window(nullptr, new Landmark(1800, 800, 50));
    window.show();
    return app.exec();
}