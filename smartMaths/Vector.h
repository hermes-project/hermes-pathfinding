//
// Created by rem on 21/02/18.
//

#ifndef HERMES_PATHFINDING_VECTOR_H
#define HERMES_PATHFINDING_VECTOR_H

/** Classe qui implément les vecteurs en coordonnées polaires et cartésiennes */
class Vector
{
public:
    /** Constructeurs */
    Vector(int x, int y);
    Vector(double ray, double theta);
    Vector();

    /** Méthodes de base */
    Vector operator+(const Vector& other)const;
    Vector operator-(const Vector& other)const;
    int distanceTo(const Vector& other)const;
    Vector clone();

    /** Getters & Setters */
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    double getRay() const;
    void setRay(double ray);
    double getTheta() const;
    void setTheta(double theta);

private:
    /** Paramètres */
    int x;
    int y;
    double ray;
    double theta;

    /** Methodes privées */
    void computePolar();
    void computeCartesian();
};


#endif //HERMES_PATHFINDING_VECTOR_H
