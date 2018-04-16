//
// Created by rem on 09/04/18.
//

#ifndef HERMES_PATHFINDING_LANDMARKFRAME_H
#define HERMES_PATHFINDING_LANDMARKFRAME_H

#include <QtWidgets/QWidget>
#include "../graph/Landmark.h"

class LandmarkFrame : public QWidget{
    Q_OBJECT

public:
    LandmarkFrame(QWidget* parent, Landmark* landmark);

private:
    Landmark* landmark;

    /** Methode qui permet de dessiner les élements du Landmark */
    void paintEvent(QPaintEvent* event);

    /** Change de référentiel un vecteur pour pouvoir l'afficher correctement */
    Vector changeToDisplay(const Vector& vector) const;
};


#endif //HERMES_PATHFINDING_LANDMARKFRAME_H
