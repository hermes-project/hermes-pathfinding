//
// Created by rem on 05/03/18.
//

#include "Ridge.h"

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
