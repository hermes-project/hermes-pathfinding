//
// Created by rem on 09/04/18.
//

#ifndef HERMES_PATHFINDING_LANDMARKFRAME_H
#define HERMES_PATHFINDING_LANDMARKFRAME_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <memory>
#include <QDebug>
#include "../graph/Graph.h"

class LandmarkFrame : public QFrame{
    Q_OBJECT

public:
    LandmarkFrame(QWidget* parent);
    void paintEvent(QPaintEvent* event);

private:
    Graph graph;
};


#endif //HERMES_PATHFINDING_LANDMARKFRAME_H
