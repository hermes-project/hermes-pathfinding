//
// Created by rem on 05/03/18.
//

#ifndef HERMES_PATHFINDING_NODE_H
#define HERMES_PATHFINDING_NODE_H

#include <vector>
#include "../smartMaths/Vector.h"

// TODO : rajouter la liste des arrêtes (ou un HashMap avec pointeur de Noeud voisin et coût associé)
class Node : public Vector{
public:
    /** Constructeurs */
    Node(int x, int y);
    Node(double ray, double theta);

    /** Créer un arrête entre ce noeud et un autre */
    void createLink(Node *node);

    /** Getters & Setters */
    Node* getPredecessor() const;
    void setPredecessor(Node* predecessor);
    int getCostFromBegin() const;
    void setCostFromBegin(int costFromBegin);
    int getHeuristic() const;
    void setHeuristic(int heuristic);

private:
    /** Informations propres au noeud */
    Node* predecessor;
    int costFromBegin;
    int heuristic;
};


#endif //HERMES_PATHFINDING_NODE_H
