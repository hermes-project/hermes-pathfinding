#include "Dijkstra.h"

Dijkstra::Dijkstra(Landmark *landmark, Graph *graph) :
    graph(graph), landmark(landmark),log(Log::getInstance()){}


std::vector<Vector> Dijkstra::findPath(const Vector begin,const Vector aim){
   if (!this->landmark->intersectAnyObstacle(begin,aim)){
        std::vector<Vector> path(2);
        path[0]= Node (begin.getX(), begin.getY());
        path[1]=aim;//
        return path;
    }

    initPithfinder(begin,aim);

    while(!openList.empty()){
        Node & visited=  openList.begin()->second;
        openList.erase(openList.begin());

        if (visited.getX()==aimNode->getX() && visited.getY()==aimNode->getY()){
            if (aimNode->getPredecessor()== nullptr){
                log->warning("position begin dans un obstacle ou hors la table");
                std::vector<Vector> path(1);
                path[0]=begin;
                return path;
            }
            return reconstructPath();
        }

        for (auto neighbour : visited.getListNeighbour()){
            int currentCost =visited.getCostFromBegin()+neighbour.second; //second est une distance
            if (currentCost<neighbour.first->getCostFromBegin()){

                //suprime le noeud de openList
                std::pair <std::multimap<int,Node>::iterator, std::multimap<int,Node>::iterator> ret;
                ret = openList.equal_range(neighbour.first->getCostFromBegin());
                for (std::multimap<int,Node>::iterator it=ret.first; it!=ret.second; ++it)
                    if (it->second.getX()==neighbour.first->getX() && it->second.getY()==neighbour.first->getY()){
                        openList.erase(it);
                        break;
                    }

                neighbour.first->setCostFromBegin(currentCost);
                neighbour.first->setPredecessor(&visited);
                openList.insert(std::make_pair(neighbour.first->getCostFromBegin(),*neighbour.first));
            }
        }
    }

    if (aimNode->getPredecessor()== nullptr){
        log->warning("position begin dans un obstacle ou hors la table");
        std::vector<Vector> path(1);
        path[0]=begin;
        return path;
    }

    return reconstructPath();


}


void Dijkstra::initPithfinder(const Vector begin,const Vector aim){
    if(!landmark->isInLandmark(begin)|| landmark->isInObstacle(begin)){
        log->warning("position begin dans un obstacle ou hors la table");
        return;
    }
    if(!landmark->isInLandmark(aim)|| landmark->isInObstacle(aim)){
        log->warning("position aim dans un obstacle ou hors la table");
        return;//TODO exception
    }
    *beginNode= Node (begin.getX(),begin.getY());
    *aimNode= Node (aim.getX(),aim.getY());

    graph->addNode(*aimNode);
    graph->addNode(*beginNode);
    graph->reinitGraph();

    beginNode->setCostFromBegin(0);
    for (auto node: graph->getStaticNodes()){
        openList.insert(std::make_pair(node.getCostFromBegin(),node));
    }
   // std::copy(graph->getStaticNodes().begin(),graph->getStaticNodes().end(),openList.begin());

    return;
}


std::vector<Vector> Dijkstra::reconstructPath(){
    std::vector<Vector> toReturn;
    Node visited=*aimNode;
    toReturn.insert(toReturn.begin(),*aimNode);
    while (!(visited.getPredecessor()->getX()==beginNode->getX() && visited.getPredecessor()->getY()==beginNode->getY())){
        toReturn.insert(toReturn.begin(),visited);
        visited=*visited.getPredecessor();
    }
    toReturn.insert(toReturn.begin(),*beginNode);
    graph->deleteNode(*beginNode);
    graph->deleteNode(*aimNode);
    openList.clear();
    return toReturn;
}
