//
// Created by rem on 05/03/18.
//

#ifndef HERMES_PATHFINDING_RIDGE_H
#define HERMES_PATHFINDING_RIDGE_H

#include "Node.h"

class Ridge {
public:
    /** Constructeur */
    Ridge(Node* node0, Node* node1);

    /** Getters & Setters */
    Node *getNode0() const;
    void setNode0(Node *node0);
    Node *getNode1() const;
    void setNode1(Node *node1);
    int getCost() const;
    void setCost(int cost);

private:
    /** Noeuds auxquels est rattachés l'arrête */
    Node* node0 ;
    Node* node1 ;

    /** Coût de l'arrête */
    int cost;
};


#endif //HERMES_PATHFINDING_RIDGE_H
