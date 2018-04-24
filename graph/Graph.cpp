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
            staticNodes.emplace_back(Node(vec.getX(), vec.getY()));
    }
}

void Graph::generateRidges() {
    std::vector<Node>::iterator it1;
    std::vector<Node>::iterator it2;
    std::vector<Circle>::iterator obstacle;
    for (it1 = staticNodes.begin(); it1 != staticNodes.end(); it1++){
        for (it2 = it1; it2 != staticNodes.end(); it2++){
            std::vector<Circle> staticObstacles = landmark->getListStaticObstacle();
            bool aucunObstacle=true;
            for (obstacle = staticObstacles.begin(); obstacle != staticObstacles.end(); obstacle++){
                if (intersect((Vector)(*it1),(Vector)(*it2),*obstacle)){
                    aucunObstacle=false;
                }
            }
            if (aucunObstacle){
                std::pair<Node*, int> pair(&(*it2), it1->distanceTo(*it2));
                (it1->getListNeighbour()).emplace(pair);
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
