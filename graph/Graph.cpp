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
    std::vector<Node> listNode=staticNodes;
    for (it1=listNode.begin();it1!=listNode.end();it1++){
        std::vector<Node>::iterator it2;
        for (it2=it1;it2!=listNode.end();it2++){
            std::vector<Circle>::iterator obstacle;
            std::vector<Circle> staticObstacles = landmark->getListStaticObstacle();
            bool aucunObstacle=true;
            for (obstacle = staticObstacles.begin(); obstacle != staticObstacles.end(); obstacle++){
                if (intersect(*it1,*it2,*obstacle)){
                    aucunObstacle=false;
                }
            }
            if (aucunObstacle){
                it1->getListRidges().emplace_back(Ridge (*it1,*it2));
            }
        }
    }
}

void Graph::update(){
    staticNodes.clear();
    generateNodes();
    generateRidges();
}

const std::vector<Node> &Graph::getStaticNodes() const {
    return staticNodes;
}
