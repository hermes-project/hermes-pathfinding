//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_WINDOW_H
#define HERMES_PATHFINDING_WINDOW_H

#include <QtWidgets/QtWidgets>
#include "../graph/Landmark.h"
#include "LandmarkFrame.h"
#include "../utils/Log.h"
#include "LogFrame.h"
#include "Menu.h"

class Window : public QWidget{
public:
    /** Constructeur et Destructeur */
    Window(QWidget* parent= nullptr, Landmark* landmark= nullptr);
    ~Window(){
        delete frame;
        delete menu;
        delete logFrame;
    }

private:
    /** Frame affichant l'état du Landmark */
    LandmarkFrame* frame;
    Menu* menu;
    LogFrame* logFrame;
};


#endif //HERMES_PATHFINDING_WINDOW_H
