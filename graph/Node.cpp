//
// Created by rem on 05/03/18.
//

#include "Node.h"

/** Constructeurs */
Node::Node(int x, int y) : Vector(x,y){}
Node::Node(double ray, double theta) : Vector(ray, theta){}

/** Créer un liens entre deux noeuds */
void Node::createLink(Node *node) {}

/** Getters & Setters */
Node *Node::getPredecessor() const {
    return predecessor;
}
void Node::setPredecessor(Node *predecessor) {
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
