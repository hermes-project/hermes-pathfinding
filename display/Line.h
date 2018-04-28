//
// Created by rem on 27/04/18.
//

#ifndef HERMES_PATHFINDING_LINE_H
#define HERMES_PATHFINDING_LINE_H


#include <QtWidgets/QLabel>

class Line : public QLabel {
public:
    /** Constructeurs */
    Line(QWidget* parent, const QString line);
    Line(const Line& line);

    /** Getter */
    const QString &getLine() const;

private:
    QString line;

    /** Le style utilisé à l'affichage */
    const QFont font = QFont("Helvetica", 10, QFont::Medium);
    const QColor textColor = QColor(220, 230, 240);
};


#endif //HERMES_PATHFINDING_LINE_H
