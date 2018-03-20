//
// Created by rem on 20/03/18.
//

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "Window.h"

Window::Window(QWidget* parent) : menu(new Menu(this))
{
    installEventFilter(this);
    QVBoxLayout* lay=new QVBoxLayout(this);
    lay->setMargin(0);
    lay->addWidget(menu);
    setLayout(lay);
}