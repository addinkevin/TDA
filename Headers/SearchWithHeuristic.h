//
// Created by kevin on 10/7/16.
//

#ifndef TDA_SEARCHWITHHEURISTIC_H
#define TDA_SEARCHWITHHEURISTIC_H


#include "Path.h"

class SearchWithHeuristic : public Path {
private:
    bool* marked;
    int* distance;
    Edge** edgeTo;
public:
    SearchWithHeuristic(Digraph *g, int source, int dest);
    virtual ~SearchWithHeuristic();

    bool visited(int v);
    double distanceTo(int v);
    std::list<Edge*> pathTo(int v);

};


#endif //TDA_SEARCHWITHHEURISTIC_H
