//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_WINDOW_H
#define HERMES_PATHFINDING_WINDOW_H

#include <QtWidgets/QWidget>
#include "Menu.h"
#include "../graph/Landmark.h"

class Window : public QWidget{
public:
    Window(QWidget* parent, Landmark* landmark);
private:
    Menu* menu;
    Landmark* landmark;
};


#endif //HERMES_PATHFINDING_WINDOW_H
