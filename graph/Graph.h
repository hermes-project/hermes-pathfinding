//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_GRAPH_H
#define HERMES_PATHFINDING_GRAPH_H


#include "Landmark.h"

#define PI 3.1415926535
#define N_NODE 10.0
#define MARGE_RAY 15.0

class Graph {
public:
    /** Constructeur */
    Graph(Landmark* landmark);

    /** Méthodes d'intialisation du graphe */
    void init(Vector& startP, Vector& aimP);
    void end(Vector& startP, Vector& aimP);

    /** Méthodes de modification du graphe */
    void update();

    /** Getters & Setters */
    const std::vector<Node> &getStaticNodes() const;

private:
    Landmark* landmark;
    std::vector<Node> staticNodes;

    /** Méthodes de création du graphe */
    void generateNodes();
    void generateRidges();
    void genNodeArnd(Circle& circle);
};


#endif //HERMES_PATHFINDING_GRAPH_H
