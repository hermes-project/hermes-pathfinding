//
// Created by rem on 05/03/18.
//

#include "Ridge.h"

/** Constructeur */
Ridge::Ridge(Node& nodeF, Node& nodeS) : nodeF(nodeF), nodeS(nodeS){
    this->cost = nodeF.distanceTo(nodeS);
}

/** Getters & Setters */
Node& Ridge::getNodeF() const {
    return nodeF;
}
void Ridge::setNodeF(Node& nodeF) {
    Ridge::nodeF = nodeF;
}
Node& Ridge::getNodeS() const {
    return nodeS;
}
void Ridge::setNodeS(Node& nodeS) {
    Ridge::nodeS = nodeS;
}
int Ridge::getCost() const {
    return cost;
}
void Ridge::setCost(int cost) {
    Ridge::cost = cost;
}
