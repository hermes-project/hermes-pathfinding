//
// Created by rem on 09/04/18.
//

#include "LandmarkFrame.h"

LandmarkFrame::LandmarkFrame(QWidget *parent, Graph* graph) :
        QFrame(parent),
        landmark(graph->getLandmark()),
        graph(graph),
        dijkstra(new Dijkstra(landmark, graph))
{
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
    pos = nullptr;
    aim = nullptr;

    ORIGIN = changeToDisplay(Vector(0,0));
    UL = changeToDisplay(landmark->getUL());
    UR = changeToDisplay(landmark->getUR());
    DL = changeToDisplay(landmark->getDL());
    DR = changeToDisplay(landmark->getDR());
    brush = QBrush(QColor(200, 210, 220, 160), Qt::SolidPattern);
    pen = QPen(QColor(255, 40, 20, 250), 0.3);

}

void LandmarkFrame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);
    painter.setBrush(brush);

    // Elements de référence : les coins et les axes du repère
    painter.drawLine(landmark->getSize_X()/2 + MARGE_X/2, 0, landmark->getSize_X()/2 + MARGE_X/2, 1000);
    painter.drawLine(0, landmark->getSize_Y()/2 + MARGE_Y/2, 2000, landmark->getSize_Y()/2 + MARGE_Y/2);
    painter.drawEllipse(ORIGIN.getX()-3, ORIGIN.getY()-3, 6, 6);
    painter.drawEllipse(UL.getX()-3, UL.getY()-3, 6, 6);
    painter.drawEllipse(UR.getX()-3, UR.getY()-3, 6, 6);
    painter.drawEllipse(DL.getX()-3, DL.getY()-3, 6, 6);
    painter.drawEllipse(DR.getX()-3, DR.getY()-3, 6, 6);

    // Les obstalces
    std::vector<Circle>::iterator it;
    std::vector<Circle> listStatic = landmark->getListStaticObstacle();
    for(it = listStatic.begin(); it!= listStatic.end(); it++){
        Vector display = changeToDisplay(it->getCenter());
        painter.drawEllipse(display.getX()-it->getWidth()/2, display.getY()-it->getWidth()/2, it->getWidth(), it->getWidth());
    }

    // Les noeuds et arrêtes du graphe
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

    //Dijkstra
    painter.setPen(QPen(QColor(40, 200, 40, 220), 2));
   if (!path.empty() ){
        for (int etape=0;etape<path.size()-1; etape++){
            Vector depart=changeToDisplay(path[etape]);
            Vector arrivee=changeToDisplay(path[etape+1]);
            painter.drawLine(depart.getX(),depart.getY(),arrivee.getX(),arrivee.getY());
        }
    }

}

void LandmarkFrame::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button()==Qt::MouseButton::LeftButton){
        int posX = event->x() - landmark->getSize_X()/2 - MARGE_X/2;
        int posY = landmark->getSize_Y()/2 - event->y() + MARGE_Y/2;
        if(!pos){
            pos = new Vector(posX, posY);
        }
        else{
            pos->setX(posX);
            pos->setY(posY);
        }
    }
    else if(event->button()==Qt::MouseButton::RightButton){
        int posX = event->x() - landmark->getSize_X()/2 - MARGE_X/2;
        int posY = landmark->getSize_Y()/2 - event->y() + MARGE_Y/2;
        if(!aim){
            aim = new Vector(posX, posY);
        }
        else{
            aim->setX(posX);
            aim->setY(posY);
        }
    }

    if (pos && aim){
        //path=dijkstra->findPath(*pos,*aim);
    }

}

Vector LandmarkFrame::changeToDisplay(const Vector &vector) const{
    return {vector.getX() + landmark->getSize_X()/2 + MARGE_X/2, landmark->getSize_Y()/2 - (vector.getY()) + MARGE_Y/2};
}