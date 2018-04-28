//
// Created by rem on 20/03/18.
//

#include "Graph.h"

Graph::Graph(Landmark *landmark) :
        landmark(landmark),
        log(Log::getInstance())
{
    generateNodes();
    generateRidges();
}

void Graph::generateNodes() {
    std::vector<Circle>::iterator it;
    std::vector<Circle> staticObstacles = landmark->getListStaticObstacle();
    for (it = staticObstacles.begin(); it != staticObstacles.end(); it++){
        genNodeArnd(*it);
    }
    staticNodes.emplace_back(landmark->getUL().getX(), landmark->getUL().getY());
    staticNodes.emplace_back(landmark->getUR().getX(), landmark->getUR().getY());
    staticNodes.emplace_back(landmark->getDL().getX(), landmark->getDL().getY());
    staticNodes.emplace_back(landmark->getDR().getX(), landmark->getDR().getY());
}

void Graph::genNodeArnd(Circle &circle) {
    int n = (int)(circle.getWidth()/N_NODE);
    for (int i=0; i<n; i++){
        Vector vec = circle.getCenter() + Vector(circle.getWidth()/2 + MARGE_RAY, ((double)i/n)*2*PI);
        if(landmark->isInLandmark(vec) && !landmark->isInObstacle(vec))
            staticNodes.emplace_back(vec.getX(), vec.getY());
    }
}

int Graph::generateRidges() {
    int counter = 0;
    std::vector<Node>::iterator it1;
    std::vector<Node>::iterator it2;
    for (it1 = staticNodes.begin(); it1 != staticNodes.end(); it1++){
        for (it2 = it1; it2 != staticNodes.end(); it2++){
            if (it1 != it2 && !landmark->intersectAnyObstacle(*it1, *it2)){
                it1->createLink(&(*it2));
                counter++;
            }
        }
    }
    return counter;
}

void Graph::update(){
    staticNodes.clear();
    auto start_time = std::chrono::high_resolution_clock::now();

    generateNodes();
    int nR = generateRidges();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    log->debug("Time to create Graph : " + std::to_string(ms) + " ms");
    log->debug(std::to_string(staticNodes.size()) + " nodes generated, " + std::to_string(nR) + " ridges generated");
    log->debug("");
}

std::vector<Node> &Graph::getStaticNodes(){
    return staticNodes;
}

Landmark *Graph::getLandmark() const {
    return landmark;
}
