//
// Created by kevin on 10/14/16.
//

#ifndef TDA_EXACTHEURISTIC_H
#define TDA_EXACTHEURISTIC_H


#include "Heuristic.h"
#include "Digraph.h"

class ExactHeuristic : public Heuristic {
private:
    Digraph* digraph;
    int dest;
public:
    ExactHeuristic(Digraph* digraph, int dest);
    virtual double getCost(int v);

};


#endif //TDA_EXACTHEURISTIC_H
