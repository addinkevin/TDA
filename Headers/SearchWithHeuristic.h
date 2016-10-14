
#ifndef TDA_SEARCHWITHHEURISTIC_H
#define TDA_SEARCHWITHHEURISTIC_H


#include "Path.h"
#include "Heuristic.h"

class SearchWithHeuristic : public Path {
public:
    SearchWithHeuristic(Digraph *g, int source, int dest, Heuristic& heuristic);
    virtual ~SearchWithHeuristic();

};


#endif //TDA_SEARCHWITHHEURISTIC_H
