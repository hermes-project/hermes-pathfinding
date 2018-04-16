//
// Created by rem on 09/04/18.
//

#include <QtGui/QPainter>
#include <QPaintEvent>
#include "LandmarkFrame.h"

LandmarkFrame::LandmarkFrame(QWidget *parent, Landmark* landmark) : QFrame(parent), landmark(landmark) {
    // La frame prend toute la place qu'elle peut prendre
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Set la couleur de fond
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(50, 60, 70));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // Events pour la souris
    installEventFilter(this);

    // Initialisation de variables...
    pos = NULL;
    aim = NULL;
}

void LandmarkFrame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QColor(255, 255, 255, 180));

    // Affichage de l'origine et des axes
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

void LandmarkFrame::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button()==Qt::MouseButton::LeftButton){
        int posX = event->x() - 940;
        int posY = landmark->getSize_Y() - event->y() - 350;
        if(pos == NULL){
            pos = new Vector(posX, posY);
        }
        else{
            pos->setX(posX);
            pos->setY(posY);
        }
    }
    else if(event->button()==Qt::MouseButton::RightButton){
        int posX = event->x() - 940;
        int posY = landmark->getSize_Y() - event->y() - 350;
        if(aim == NULL){
            aim = new Vector(posX, posY);
        }
        else{
            aim->setX(posX);
            aim->setY(posY);
        }
    }
}

Vector LandmarkFrame::changeToDisplay(const Vector &vector) const{
    return Vector(vector.getX() + 940, landmark->getSize_Y() - (vector.getY() + 350));
}