//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_WINDOW_H
#define HERMES_PATHFINDING_WINDOW_H


#include <QtWidgets/QWidget>
#include "Menu.h"

class Window : public QWidget{
public:
    Window(QWidget* parent);
private:
    Menu* menu;
};


#endif //HERMES_PATHFINDING_WINDOW_H
