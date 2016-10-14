
#include "../Headers/OptimisticHeuristic.h"
#include "../Headers/Dijkstra.h"

OptimisticHeuristic::OptimisticHeuristic(Digraph *digraph, int dest) {
    this->digraph = digraph;
    this->dest = dest;
}

double OptimisticHeuristic::getCost(int v) {
    Dijkstra dijkstra(this->digraph, v, this->dest);
    int distance = dijkstra.distanceTo(this->dest);
    return distance - std::rand() % (distance+1);
}
