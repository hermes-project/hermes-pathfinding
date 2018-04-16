//
// Created by rem on 09/04/18.
//

#ifndef HERMES_PATHFINDING_LANDMARKFRAME_H
#define HERMES_PATHFINDING_LANDMARKFRAME_H

#include <QtWidgets/QFrame>
#include "../graph/Landmark.h"

class LandmarkFrame : public QFrame{
    Q_OBJECT

    /** Evènement de souris ! */
    void mouseReleaseEvent(QMouseEvent* event);

public slots:
    void regenerate(){
        landmark->reInitObstacle();
        update();
    };
    void add(){
        landmark->addObstacle();
        update();
    }

public:
    LandmarkFrame(QWidget* parent, Landmark* landmark);
    ~LandmarkFrame(){
        delete pos;
        delete aim;
        delete landmark;
    }

    /** Methode qui permet de dessiner les élements du Landmark, c'est la principale méthode à modifier */
    void paintEvent(QPaintEvent* event);

private:
    /** Objets qui contiennent tout ce qu'il faut afficher */
    //TODO Ajouter le graph
    Landmark* landmark;
    Vector* pos;
    Vector* aim;

    /** Change de référentiel un vecteur pour pouvoir l'afficher correctement */
    Vector changeToDisplay(const Vector& vector) const;
};


#endif //HERMES_PATHFINDING_LANDMARKFRAME_H
