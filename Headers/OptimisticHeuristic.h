
#ifndef TDA_OPTIMISTHEURISTIC_H
#define TDA_OPTIMISTHEURISTIC_H

#include "Heuristic.h"
#include "Digraph.h"

class OptimisticHeuristic : public Heuristic {
private:
    Digraph* digraph;
    int dest;
public:
    OptimisticHeuristic(Digraph* digraph, int dest);
    virtual double getCost(int v);

};


#endif //TDA_OPTIMISTHEURISTIC_H
