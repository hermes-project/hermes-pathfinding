//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_GRAPH_H
#define HERMES_PATHFINDING_GRAPH_H

#include "Landmark.h"
#include "../smartMaths/maths_lib.h"
#include "../utils/Log.h"

#define PI 3.1415926535
#define N_NODE 15.0
#define MARGE_RAY 12.0

class Graph {
public:
    /** Constructeur & Destructeur */
    explicit Graph(Landmark* landmark);
    ~Graph(){
        delete landmark;
    }

    /** Méthodes d'intialisation du graphe */
    void init(Vector& startP, Vector& aimP);
    void end(Vector& startP, Vector& aimP);

    /** Méthodes de modification du graphe */
    void update();

    /** Getters & Setters */
    std::vector<Node> &getStaticNodes();
    Landmark *getLandmark() const;

    /**Méthodes utilisés en Dijkstra**/
    void addNode(Node& node);
    void deleteNode(Node& node);
    void reinitGraph();

private:
    Log* log;
    Landmark* landmark;
    std::vector<Node> staticNodes;

    /** Méthodes de création du graphe */
    void generateNodes();
    int generateRidges();
    void genNodeArnd(Circle& circle);
    void replaceRidges(Node & node);

};


#endif //HERMES_PATHFINDING_GRAPH_H
