//
// Created by rem on 26/04/18.
//

#ifndef HERMES_PATHFINDING_LOG_H
#define HERMES_PATHFINDING_LOG_H

#include <QtWidgets/QtWidgets>
#include "Line.h"

#define TEXT_SIZE 12

class Log : public QFrame {
    Q_OBJECT
public:
    Log(QWidget* parent, int size_Y);

private:
    std::vector<Line> lines;
    int nbLine;
    QVBoxLayout* layout;
};


#endif //HERMES_PATHFINDING_LOG_H
