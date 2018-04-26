//
// Created by rem on 27/04/18.
//

#ifndef HERMES_PATHFINDING_LINE_H
#define HERMES_PATHFINDING_LINE_H


#include <QtWidgets/QLabel>

class Line : public QLabel {
public:
    Line(QWidget* parent, const QString line);
    Line* clone();

private:
    QString line;
    const QFont font = QFont("Helvetica", 11, QFont::Medium);
    const QColor textColor = QColor(220, 230, 240);
};


#endif //HERMES_PATHFINDING_LINE_H
