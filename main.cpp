#include <QtWidgets/QApplication>
#include "display/Window.h"

// Pour le moment c'est un foure-tout pour les tests, histoire de bien apprendre le C++
int main(int argc, char** argv) {

    QApplication app(argc, argv);
    Window window(NULL, new Landmark(1800, 800, 30));
    window.show();
    return app.exec();
}