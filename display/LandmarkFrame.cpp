//
// Created by rem on 09/04/18.
//

#include "LandmarkFrame.h"

LandmarkFrame::LandmarkFrame(QWidget *parent, Landmark* landmark, Graph* graph) : QFrame(parent), landmark(landmark), graph(graph) {
    // La frame prend toute la place qu'elle peut prendre
    this->setFixedSize(landmark->getSize_X() + MARGE_X, landmark->getSize_Y() + MARGE_Y);

    // Set la couleur de fond
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(60, 70, 80));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // Events pour la souris
    installEventFilter(this);

    // Initialisation de variables...
    pos = NULL;
    aim = NULL;
    ORIGIN = changeToDisplay(Vector(0,0));
    UL = changeToDisplay(Vector(-landmark->getSize_X()/2, -landmark->getSize_Y()/2));
    UR = changeToDisplay(Vector(landmark->getSize_X()/2, -landmark->getSize_Y()/2));
    DL = changeToDisplay(Vector(-landmark->getSize_X()/2, landmark->getSize_Y()/2));
    DR = changeToDisplay(Vector(landmark->getSize_X()/2, landmark->getSize_Y()/2));
    brush = QBrush(QColor(200, 210, 220, 160), Qt::SolidPattern);
    pen = QPen(QColor(100, 20, 20, 250), 0.3);
}

void LandmarkFrame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawLine(landmark->getSize_X()/2 + MARGE_X/2, 0, landmark->getSize_X()/2 + MARGE_X/2, 1000);
    painter.drawLine(0, landmark->getSize_Y()/2 + MARGE_Y/2, 2000, landmark->getSize_Y()/2 + MARGE_Y/2);
    painter.drawEllipse(ORIGIN.getX()-5, ORIGIN.getY()-5, 10, 10);
    painter.drawEllipse(UL.getX()-5, UL.getY()-5, 10, 10);
    painter.drawEllipse(UR.getX()-5, UR.getY()-5, 10, 10);
    painter.drawEllipse(DL.getX()-5, DL.getY()-5, 10, 10);
    painter.drawEllipse(DR.getX()-5, DR.getY()-5, 10, 10);

    std::vector<Circle>::iterator it;
    std::vector<Circle> listStatic = landmark->getListStaticObstacle();
    for(it = listStatic.begin(); it!= listStatic.end(); it++){
        Vector display = changeToDisplay(it->getCenter());
        painter.drawEllipse(display.getX()-it->getWidth()/2, display.getY()-it->getWidth()/2, it->getWidth(), it->getWidth());
    }

    std::vector<Node>::iterator itNode;
    std::map<Node*, int>::iterator itNodeN;
    for(itNode = (graph->getStaticNodes()).begin(); itNode!= (graph->getStaticNodes()).end(); itNode++){
        Vector display = changeToDisplay(*itNode);
        painter.drawEllipse(display.getX()-1, display.getY()-1, 2, 2);
        for(itNodeN = (itNode->getListNeighbour()).begin(); itNodeN != (itNode->getListNeighbour()).end(); itNodeN++){
            Vector displayN = changeToDisplay(*(itNodeN->first));
            painter.drawLine(display.getX(), display.getY(), displayN.getX(), displayN.getY());
        }
    }
}

void LandmarkFrame::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button()==Qt::MouseButton::LeftButton){
        int posX = event->x() - 940;
        int posY = landmark->getSize_Y() - event->y() - 350;
        if(!pos){
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
        if(!aim){
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