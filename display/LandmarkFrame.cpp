//
// Created by rem on 09/04/18.
//

#include <QtGui/QPainter>
#include <QPaintEvent>
#include "LandmarkFrame.h"

LandmarkFrame::LandmarkFrame(QWidget *parent, Landmark* landmark, Graph* graph) : QFrame(parent), landmark(landmark), graph(graph) {
    // La frame prend toute la place qu'elle peut prendre
    this->setFixedSize(landmark->getSize_X() + MARGE_X, landmark->getSize_Y() + MARGE_Y);

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
    Vector ul(-landmark->getSize_X()/2, -landmark->getSize_Y()/2);
    Vector ur(landmark->getSize_X()/2, -landmark->getSize_Y()/2);
    Vector dl(-landmark->getSize_X()/2, landmark->getSize_Y()/2);
    Vector dr(landmark->getSize_X()/2, landmark->getSize_Y()/2);
    Vector originDisplay = changeToDisplay(origin);
    Vector ulDisplay = changeToDisplay(ul);
    Vector urDisplay = changeToDisplay(ur);
    Vector dlDisplay = changeToDisplay(dl);
    Vector drDisplay = changeToDisplay(dr);

    painter.drawLine(landmark->getSize_X()/2, 0, landmark->getSize_X()/2, 1000);
    painter.drawLine(0, landmark->getSize_Y()/2, 2000, landmark->getSize_Y()/2);
    painter.drawEllipse(originDisplay.getX()-5, originDisplay.getY()-5, 10, 10);
    painter.drawEllipse(ulDisplay.getX()-5, ulDisplay.getY()-5, 10, 10);
    painter.drawEllipse(urDisplay.getX()-5, urDisplay.getY()-5, 10, 10);
    painter.drawEllipse(dlDisplay.getX()-5, dlDisplay.getY()-5, 10, 10);
    painter.drawEllipse(drDisplay.getX()-5, drDisplay.getY()-5, 10, 10);

    painter.setBrush(QBrush(QColor(200, 210, 220, 160), Qt::SolidPattern));
    std::vector<Circle>::iterator it;
    std::vector<Circle> listStatic = landmark->getListStaticObstacle();
    for(it = listStatic.begin(); it!= listStatic.end(); it++){
        Vector display = changeToDisplay(it->getCenter());
        painter.drawEllipse(display.getX()-it->getWidth()/2, display.getY()-it->getWidth()/2, it->getWidth(), it->getWidth());
    }

    painter.setBrush(QBrush(QColor(210, 80, 80, 220), Qt::SolidPattern));
    std::vector<Node>::iterator itNode;
    std::vector<Node> listNode = graph->getStaticNodes();
    for(itNode = listNode.begin(); itNode!= listNode.end(); itNode++){
        Vector display = changeToDisplay(*itNode);
        painter.drawEllipse(display.getX()-1, display.getY()-1, 2, 2);
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
    return Vector(vector.getX() + landmark->getSize_X()/2 + MARGE_X/2, landmark->getSize_Y()/2 - (vector.getY()) + MARGE_Y/2);
}