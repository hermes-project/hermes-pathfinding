//
// Created by rem on 05/03/18.
//

#include "Node.h"

/** Constructeurs */
Node::Node(int x, int y) : Vector(x,y), predecessor(nullptr){}
Node::Node(double ray, double theta) : Vector(ray, theta), predecessor(nullptr){}

/** Créer un liens entre deux noeuds */
void Node::createLink(Node *node) {
    int distance = this->distanceTo(*node);
    this->getListNeighbour().emplace(node, distance);
    node->getListNeighbour().emplace(this, distance);
}

/** Getters & Setters */
Node* Node::getPredecessor() const {
    return predecessor;
}
void Node::setPredecessor(Node* predecessor) {
    Node::predecessor = predecessor;
}
int Node::getCostFromBegin() const {
    return costFromBegin;
}
void Node::setCostFromBegin(int costFromBegin) {
    Node::costFromBegin = costFromBegin;
}
int Node::getHeuristic() const {
    return heuristic;
}
void Node::setHeuristic(int heuristic) {
    Node::heuristic = heuristic;
}

std::map<Node*, int> &Node::getListNeighbour(){
    return listNeighbour;
}
