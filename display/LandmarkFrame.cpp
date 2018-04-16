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
    Vector origin(0,0);
    Vector originDisplay = changeToDisplay(origin);

    painter.drawLine(940, 0, 940, 1000);
    painter.drawLine(0, 450, 2000, 450);
    painter.drawEllipse(originDisplay.getX()-5, originDisplay.getY()-5, 10, 10);

    painter.setBrush(QBrush(QColor(200, 210, 220, 160), Qt::SolidPattern));
    std::vector<Circle>::iterator it;
    std::vector<Circle> listStatic = landmark->getListStaticObstacle();
    for(it = listStatic.begin(); it!= listStatic.end(); it++){
        Vector display = changeToDisplay(it->getCenter());
        painter.drawEllipse(display.getX()-it->getWidth()/2, display.getY()-it->getWidth()/2, it->getWidth(), it->getWidth());
    }
}

Vector LandmarkFrame::changeToDisplay(const Vector &vector) const{
    return Vector(vector.getX() + 940, landmark->getSize_Y() - (vector.getY() + 350));
}