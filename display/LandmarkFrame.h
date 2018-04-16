//
// Created by rem on 09/04/18.
//

#ifndef HERMES_PATHFINDING_LANDMARKFRAME_H
#define HERMES_PATHFINDING_LANDMARKFRAME_H

#include <QtWidgets/QWidget>
#include "../graph/Landmark.h"

class LandmarkFrame : public QWidget{
    Q_OBJECT

public:
    LandmarkFrame(QWidget* parent, Landmark* landmark);

private:
    Landmark* landmark;
    void paintEvent(QPaintEvent* event);
};


#endif //HERMES_PATHFINDING_LANDMARKFRAME_H
