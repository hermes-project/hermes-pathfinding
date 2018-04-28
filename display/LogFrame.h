//
// Created by rem on 26/04/18.
//

#ifndef HERMES_PATHFINDING_LOGFRAME_H
#define HERMES_PATHFINDING_LOGFRAME_H

#include <QtWidgets/QtWidgets>
#include <queue>
#include "Line.h"

#define TEXT_SIZE 21

class LogFrame : public QFrame {
    Q_OBJECT
public:
    /** Constructeur */
    LogFrame(QWidget* parent, int size_Y);

    /** Methodes permettant d'afficher une ligne sur la frame */
    void debug(const std::string mess);
    void warning(const std::string mess);
    void error(const std::string mess);

    /** Getter */
    int getNbLine() const;

private:
    int nbLine;
    int limitLine;
    QVBoxLayout* layout;
};


#endif //HERMES_PATHFINDING_LOGFRAME_H
