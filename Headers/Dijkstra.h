
#ifndef TDA_DIJKSTRA_H
#define TDA_DIJKSTRA_H

#include "Path.h"

class Dijkstra : public Path {
public:
    Dijkstra(Digraph *g, int source, int dest);
    virtual ~Dijkstra();

};
#endif //TDA_DIJKSTRA_H
