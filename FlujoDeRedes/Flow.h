//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_FLOW_H
#define TRABAJOPRACTICO2_FLOW_H


#include "Digraph.h"
#include "EdgeInfo.h"
#include <map>

using namespace std;

class Flow {
    map<Edge*,EdgeInfo*> edgeMap;
    Digraph* digraph;
    void init();
public:
    Flow(Digraph* digraph);
    ~Flow();

    EdgeInfo* getEdgeInfo(Edge* edge);
};


#endif //TRABAJOPRACTICO2_FLOW_H
