
#ifndef TDA_PESIMISTHEURISTIC_H
#define TDA_PESIMISTHEURISTIC_H

#include "Heuristic.h"
#include "Digraph.h"

class PessimisticHeuristic : public Heuristic {
private:
    Digraph* digraph;
    int dest;
public:
    PessimisticHeuristic(Digraph* digraph, int dest);
    virtual double getCost(int v);

};


#endif //TDA_PESIMISTHEURISTIC_H
