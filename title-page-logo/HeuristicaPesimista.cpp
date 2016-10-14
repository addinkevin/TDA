#include "../Headers/PessimisticHeuristic.h"
#include "../Headers/Dijkstra.h"
#include "../Headers/PathBFS.h"

PessimisticHeuristic::PessimisticHeuristic(Digraph *digraph, int dest) {
    this->digraph = digraph;
    this->dest = dest;
}

double PessimisticHeuristic::getCost(int v) {
    PathBFS pathBFS(this->digraph, v, this->dest);
    return pathBFS.distanceTo(this->dest);
}
