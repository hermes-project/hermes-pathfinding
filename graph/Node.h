//
// Created by rem on 05/03/18.
//

#ifndef HERMES_PATHFINDING_NODE_H
#define HERMES_PATHFINDING_NODE_H

#include <vector>
#include <map>
#include "../smartMaths/Vector.h"

class Node : public Vector{
public:
    /** Constructeurs & Destructeur */
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
    std::map<Node *, int> &getListNeighbour();

private:
    /** Informations propres au noeud */
    Node* predecessor;
    int costFromBegin;
    int heuristic;
    std::map<Node*, int> listNeighbour;
};


#endif //HERMES_PATHFINDING_NODE_H
