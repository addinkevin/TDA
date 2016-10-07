//
// Created by kevin on 10/7/16.
//

#include "../Headers/SearchWithHeuristic.h"

SearchWithHeuristic::SearchWithHeuristic(Digraph *g, int source, int dest) : Path(g, source, dest) {

}


bool SearchWithHeuristic::visited(int v) {
    return false;
}

double SearchWithHeuristic::distanceTo(int v) {
    return 0;
}

std::list<Edge *> SearchWithHeuristic::pathTo(int v) {
    return std::list<Edge *>();
}

SearchWithHeuristic::~SearchWithHeuristic() {

}
