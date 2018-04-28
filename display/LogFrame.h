//
// Created by rem on 26/04/18.
//

#ifndef HERMES_PATHFINDING_LOGFRAME_H
#define HERMES_PATHFINDING_LOGFRAME_H

#include <QtWidgets/QtWidgets>
#include <queue>
#include "Line.h"

#define TEXT_SIZE 22

class LogFrame : public QFrame {
    Q_OBJECT
public:
    /** Constructeur */
    LogFrame(QWidget* parent, int size_Y);

    /** Methodes permettant d'afficher une ligne sur la frame */
    void debug(const char* line);
    void warning(const char* line);
    void error(const char* line);

    /** Getter */
    int getNbLine() const;

private:
    std::queue<Line*> lines;
    int nbLine;
    QVBoxLayout* layout;
};


#endif //HERMES_PATHFINDING_LOGFRAME_H
