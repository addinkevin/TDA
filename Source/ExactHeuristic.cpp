
#include "../Headers/ExactHeuristic.h"
#include "../Headers/Dijkstra.h"

ExactHeuristic::ExactHeuristic(Digraph *digraph, int dest) {
    this->digraph = digraph;
    this->dest = dest;
}

double ExactHeuristic::getCost(int v) {
    Dijkstra dijkstra(this->digraph, v, this->dest);
    return dijkstra.distanceTo(this->dest);
}
