
#ifndef TDA_ASTAR_H
#define TDA_ASTAR_H


#include "Path.h"
#include "Heuristic.h"

class AStar : public Path {
public:
    AStar(Digraph *g, int source, int dest, Heuristic& heuristic);
    virtual ~AStar();

};


#endif //TDA_ASTAR_H
