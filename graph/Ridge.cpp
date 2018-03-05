//
// Created by rem on 05/03/18.
//

#include "Ridge.h"
/** Constructeur */
Ridge::Ridge(Node *node0, Node *node1) {
    this->node0 = node0;
    this->node1 = node1;
    this->cost = node0->distanceTo(*node1);
}

/** Getters & Setters */
Node *Ridge::getNode0() const {
    return node0;
}
void Ridge::setNode0(Node *node0) {
    Ridge::node0 = node0;
}
Node *Ridge::getNode1() const {
    return node1;
}
void Ridge::setNode1(Node *node1) {
    Ridge::node1 = node1;
}
int Ridge::getCost() const {
    return cost;
}
void Ridge::setCost(int cost) {
    Ridge::cost = cost;
}
