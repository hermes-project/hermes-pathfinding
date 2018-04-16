//
// Created by rem on 09/04/18.
//

#include <QtGui/QPainter>
#include "LandmarkFrame.h"

LandmarkFrame::LandmarkFrame(QWidget *parent, Landmark* landmark) : QWidget(parent), landmark(landmark) {
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(50, 60, 70));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void LandmarkFrame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // painter.setPen(QPen(Qt::darkRed, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(835, 350, 200, 200);
}