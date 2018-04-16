//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_WINDOW_H
#define HERMES_PATHFINDING_WINDOW_H

#define MARGE_X 102
#define MARGE_Y 170

#include <QtWidgets/QWidget>
#include "../graph/Landmark.h"
#include "LandmarkFrame.h"

class Window : public QWidget{
public:
    Window(QWidget* parent=0, Landmark* landmark=0);

private:
    /** Frame affichant l'état du Landmark */
    LandmarkFrame* frame;
};


#endif //HERMES_PATHFINDING_WINDOW_H
