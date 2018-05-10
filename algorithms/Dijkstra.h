#ifndef HERMES_PATHFINDING_DIJKSTRA_H
#define HERMES_PATHFINDING_DIJKSTRA_H

#include "../graph/Landmark.h"
#include "../graph/Graph.h"
#include "../graph/Node.h"
#include "../smartMaths/Vector.h"



class Dijkstra {
public:
    Dijkstra(Landmark* landmark, Graph* graph);
    std::vector<Vector> findPath( Vector begin, Vector aim);
private:
    Node *beginNode= nullptr;
    Node *aimNode= nullptr;
    std::multimap<int,Node> openList;
    void initPithfinder( Vector begin,  Vector aim);
    std::vector<Vector> reconstructPath();
    Graph *graph;
    Landmark *landmark;
    Log *log;
};


#endif //HERMES_PATHFINDING_DIJKSTRA_H
