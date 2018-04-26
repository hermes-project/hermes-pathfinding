//
// Created by rem on 20/03/18.
//

#include "Graph.h"

Graph::Graph(Landmark *landmark) : landmark(landmark){
    generateNodes();
    generateRidges();
}

void Graph::generateNodes() {
    std::vector<Circle>::iterator it;
    std::vector<Circle> staticObstacles = landmark->getListStaticObstacle();
    for (it = staticObstacles.begin(); it != staticObstacles.end(); it++){
        genNodeArnd(*it);
    }
}

void Graph::genNodeArnd(Circle &circle) {
    int n = (int)(circle.getWidth()/N_NODE);
    for (int i=0; i<n; i++){
        Vector vec = circle.getCenter() + Vector(circle.getWidth()/2 + MARGE_RAY, ((double)i/n)*2*PI);
        if(landmark->isInLandmark(vec) && !landmark->isInObstacle(vec))
            staticNodes.emplace_back(vec.getX(), vec.getY());
    }
}

void Graph::generateRidges() {
    std::vector<Node>::iterator it1;
    std::vector<Node>::iterator it2;
    std::vector<Circle>::iterator obstacle;
    for (it1 = staticNodes.begin(); it1 != staticNodes.end(); it1++){
        for (it2 = it1; it2 != staticNodes.end(); it2++){
            bool aucunObstacle=true;
            for (obstacle = (landmark->getListStaticObstacle()).begin(); obstacle != (landmark->getListStaticObstacle()).end(); obstacle++){
                if (intersect((*it1),(*it2),*obstacle)){
                    aucunObstacle=false;
                }
            }
            if (aucunObstacle){
                (it1->getListNeighbour()).emplace(&(*it2), it1->distanceTo(*it2));
            }
        }
    }
}

void Graph::update(){
    staticNodes.clear();
    generateNodes();
    generateRidges();
}

std::vector<Node> &Graph::getStaticNodes(){
    return staticNodes;
}
