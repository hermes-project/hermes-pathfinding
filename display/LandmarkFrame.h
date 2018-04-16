//
// Created by rem on 09/04/18.
//

#ifndef HERMES_PATHFINDING_LANDMARKFRAME_H
#define HERMES_PATHFINDING_LANDMARKFRAME_H

#define NB_OBSTACLE 80

#include <QtWidgets/QFrame>
#include "../graph/Landmark.h"

class LandmarkFrame : public QFrame{
    Q_OBJECT

    /** Evènement de souris ! */
    void mouseReleaseEvent(QMouseEvent* event);

public slots:
    void regenerate(){
        landmark->initObstacle(NB_OBSTACLE);
        update();
    };

public:
    LandmarkFrame(QWidget* parent, Landmark* landmark);
    ~LandmarkFrame(){
        delete pos;
        delete aim;
        delete landmark;
    }

    /** Methode qui permet de dessiner les élements du Landmark */
    void paintEvent(QPaintEvent* event);

private:
    Landmark* landmark;
    Vector* pos;
    Vector* aim;

    /** Change de référentiel un vecteur pour pouvoir l'afficher correctement */
    Vector changeToDisplay(const Vector& vector) const;
};


#endif //HERMES_PATHFINDING_LANDMARKFRAME_H
