//
// Created by kevin on 10/7/16.
//

#ifndef TDA_ASTAR_H
#define TDA_ASTAR_H


#include "Path.h"
#include "Heuristic.h"

class AStar : public Path {
private:
    bool* marked;
    double* distance;
    Edge** edgeTo;
public:
    AStar(Digraph *g, int source, int dest, Heuristic& heuristic);
    virtual ~AStar();

    bool visited(int v);
    double distanceTo(int v);
    std::list<Edge*> pathTo(int v);

};


#endif //TDA_ASTAR_H
