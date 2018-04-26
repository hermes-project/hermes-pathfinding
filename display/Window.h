//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_WINDOW_H
#define HERMES_PATHFINDING_WINDOW_H

#include <QtWidgets/QtWidgets>
#include "../graph/Landmark.h"
#include "LandmarkFrame.h"
#include "Log.h"
#include "Menu.h"

class Window : public QWidget{
public:
    Window(QWidget* parent= nullptr, Landmark* landmark= nullptr);
    ~Window(){
        delete frame;
        delete menu;
        delete log;
    }

private:
    /** Frame affichant l'état du Landmark */
    LandmarkFrame* frame;
    Menu* menu;
    Log* log;
};


#endif //HERMES_PATHFINDING_WINDOW_H
