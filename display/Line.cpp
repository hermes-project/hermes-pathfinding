//
// Created by rem on 27/04/18.
//

#include "Line.h"

Line::Line(QWidget* parent, const QString line) : QLabel(parent), line(line){
    this->setAlignment(Qt::AlignTop);
    this->setFont(font);

    QPalette palette;
    palette.setColor(QPalette::WindowText, textColor);
    this->setPalette(palette);
    this->setText(line);
}

Line::Line(const Line &line) {
    this->setParent(line.nativeParentWidget());
    this->line = line.getLine();
}

const QString &Line::getLine() const {
    return line;
}
