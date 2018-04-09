//
// Created by rem on 20/03/18.
//

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "Window.h"

Window::Window(QWidget* parent, Landmark* landmark) : menu(new Menu(this)), landmark(landmark)
{
    QVBoxLayout* lay=new QVBoxLayout(this);
    lay->setMargin(0);
    lay->addWidget(menu);
    lay->addWidget(landmarkPanel);
    setLayout(lay);
}