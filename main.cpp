#include <QtWidgets/QApplication>
#include "display/Window.h"

// Pour le moment c'est un foure-tout pour les tests, histoire de bien apprendre le C++
// Pour faire le liens entre la partie fonctionnelle et la partie affichage, voir la classe LandmarkFrame
int main(int argc, char** argv) {

    QApplication app(argc, argv);
    Window window(NULL, new Landmark(1800, 800, 10));
    window.show();
    return app.exec();

    /*
    Landmark* landmark = new Landmark(2000, 1000, 100);
    Graph graph(landmark);

    landmark->addObstacle();
    graph.update();
     */

    return EXIT_SUCCESS;
}