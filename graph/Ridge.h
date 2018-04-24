//
// Created by rem on 05/03/18.
//

#ifndef HERMES_PATHFINDING_RIDGE_H
#define HERMES_PATHFINDING_RIDGE_H

#include "Node.h";

class Ridge {
public:
    /** Constructeur */
    Ridge(Node& nodeF, Node& nodeS);

    /** Getters & Setters */
    Node& getNodeF() const;
    void setNodeF(Node &nodeF);
    Node& getNodeS() const;
    void setNodeS(Node &nodeS);
    int getCost() const;
    void setCost(int cost);

private:
    /** Noeuds auxquels est rattachés l'arrête */
    Node &nodeF ;
    Node &nodeS ;

    /** Coût de l'arrête */
    int cost;
};


#endif //HERMES_PATHFINDING_RIDGE_H
