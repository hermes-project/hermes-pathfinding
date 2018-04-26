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

Line* Line::clone() {
    return new Line(this->nativeParentWidget(), line);
}