//
// Created by kevin on 10/8/16.
//

#ifndef TDA_DIJKSTRA_H
#define TDA_DIJKSTRA_H

#include "Path.h"

class Dijkstra : public Path {
private:
    bool* marked;
    double* distance;
    Edge** edgeTo;
public:
    Dijkstra(Digraph *g, int source, int dest);
    virtual ~Dijkstra();

    bool visited(int v);
    double distanceTo(int v);
    std::list<Edge*> pathTo(int v);

};
#endif //TDA_DIJKSTRA_H
