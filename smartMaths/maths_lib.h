//
// Created by rem on 28/02/18.
//

#include "Vector.h"
#include "Ellipse.h"
#include "Circle.h"
#include <cmath>

#ifndef HERMES_PATHFINDING_MATHS_LIB_H
#define HERMES_PATHFINDING_MATHS_LIB_H

/** Fonction qui calcul le modulo entre -module/2 et +module/2
 * @param value la valeur (d'angle par exemple)
 * @param module
 */
static double modulo(double value, double module){
    auto q = (int) (value/module);
    value = value - q*module;
    if(value >= module/2){
        value = value - module;
    }
    return value;
}

/** Renvoie true s'il y a intersection entre le segment et le cercle
 * @param vector0 vector1 les vecteurs qui délimitent le segment
 * @param circle le cercle
 */
static bool intersect(const Vector vector0, const Vector vector1, const Circle circle){
    // TODO : faire un dessin
    /*
    Vector segment = vector1-vector0;
    Vector zeroToCenter = circle.getCenter()-vector0;
    int distance = (int) (zeroToCenter.getRay()*sin(zeroToCenter.getTheta()-segment.getTheta()));

    // Si la distance entre la droite porteuse du segment et le centre du cercle est supérieure au rayon, pas d'intersection
    if(distance > circle.getWidth()){
        return false;
    }

    // Sinon on vérifie que le centre du cercle soit dans le triangle définit par l'origine et les deux points délimitant le segment
    return !((circle.getCenter().getY()*vector0.getX() < vector0.getY() * circle.getCenter().getX()) && (circle.getCenter().getY()*vector0.getX() < vector1.getY() * circle.getCenter().getX())
             || (circle.getCenter().getY()*vector0.getX() > vector0.getY() * circle.getCenter().getX()) && (circle.getCenter().getY()*vector1.getX() > vector1.getY()*circle.getCenter().getX()));
    */
    double area = ((double)circle.getCenter().getX() - (double)vector0.getX())*((double)vector1.getY() - (double)vector0.getY()) - ((double)circle.getCenter().getY() - (double)vector0.getY())*((double)vector1.getX() - (double)vector0.getX());
    double distA = ((double)vector0.getX() - (double)circle.getCenter().getX())*((double)vector0.getX() - (double)circle.getCenter().getX()) + ((double)vector0.getY() - (double)circle.getCenter().getY())*((double)vector0.getY() - (double)circle.getCenter().getY());
    double distB = ((double)vector1.getX() - (double)circle.getCenter().getX())*((double)vector1.getX() - (double)circle.getCenter().getX()) + ((double)vector1.getY() - (double)circle.getCenter().getY())*((double)vector1.getY() - (double)circle.getCenter().getY());
    if(distA >= circle.getWidth()/2 * circle.getWidth()/2 && distB < circle.getWidth()/2 * circle.getWidth()/2 || distA < circle.getWidth()/2 * circle.getWidth()/2 && distB >= circle.getWidth()/2 * circle.getWidth()/2)
        return true;
    return distA >= circle.getWidth()/2 * circle.getWidth()/2
           && distB >= circle.getWidth()/2 * circle.getWidth()/2
           && area * area / (((double)vector1.getX() - (double)vector0.getX())*((double)vector1.getX() - (double)vector0.getX())+((double)vector1.getY() - (double)vector0.getY())*((double)vector1.getY() - (double)vector0.getY())) <= circle.getWidth()/2 * circle.getWidth()/2
           && ((double)vector1.getX() - (double)vector0.getX())*((double)circle.getCenter().getX() - (double)vector0.getX()) + ((double)vector1.getY() - (double)vector0.getY())*((double)circle.getCenter().getY() - (double)vector0.getY()) >= 0
           && ((double)vector0.getX() - (double)vector1.getX())*((double)circle.getCenter().getX() - (double)vector1.getX()) + ((double)vector0.getY() - (double)vector1.getY())*((double)circle.getCenter().getY() - (double)vector1.getY()) >= 0;

}

#endif //HERMES_PATHFINDING_MATHS_LIB_H