//
// Created by rem on 09/04/18.
//

#ifndef HERMES_PATHFINDING_LANDMARKFRAME_H
#define HERMES_PATHFINDING_LANDMARKFRAME_H

#include <QtWidgets/QFrame>
#include <QPainter>
#include <QPaintEvent>
#include "../graph/Landmark.h"
#include "../graph/Graph.h"

#define MARGE_X 20
#define MARGE_Y 20

class LandmarkFrame : public QFrame{
    Q_OBJECT

    /** Evènement de souris ! */
    void mouseReleaseEvent(QMouseEvent* event) override ;

public slots:
    /** Méthode appelées en cas d'appuie sur un bouton du menu */
    void regenerate(){
        landmark->reInitObstacle();
        graph->update();
        update();
    };
    void add(){
        landmark->addObstacle();
        graph->update();
        update();
    }

public:
    /** Constructeur & Destructeur */
    LandmarkFrame(QWidget* parent, Graph* graph);
    ~LandmarkFrame() override {
        delete pos;
        delete aim;
        delete graph;
    }

    /** Methode qui permet de dessiner les élements du Landmark, c'est la principale méthode à modifier */
    void paintEvent(QPaintEvent* event) override ;

private:
    /** Objets qui contiennent tout ce qu'il faut afficher */
    Landmark* landmark;
    Graph* graph;
    Vector* pos;
    Vector* aim;

    /** Constantes d'affichage */
    Vector ORIGIN;
    Vector UL;
    Vector UR;
    Vector DL;
    Vector DR;

    QBrush brush;
    QPen pen;

    /** Change de référentiel un vecteur pour pouvoir l'afficher correctement */
    Vector changeToDisplay(const Vector& vector) const;
};


#endif //HERMES_PATHFINDING_LANDMARKFRAME_H
