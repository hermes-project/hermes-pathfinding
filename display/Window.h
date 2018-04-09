//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_WINDOW_H
#define HERMES_PATHFINDING_WINDOW_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include "Menu.h"
#include "../graph/Landmark.h"

class Window : public QWidget{
    Q_OBJECT
public:
    Window(QWidget* parent=0, Landmark* landmark);
    virtual ~MainWindow(){
        delete menu;
        delete landmark;
    }

private:
    Menu* menu;
    Landmark* landmark;
};


#endif //HERMES_PATHFINDING_WINDOW_H
