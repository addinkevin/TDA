#include "Flow.h"

Flow::Flow(Digraph *digraph) {
    this->digraph = digraph;
    this->init();
}

void Flow::init() {
    // f(e) = 0 para toda arista del grafo.
    for (int v = 0; v < this->digraph->getVertices(); v++) {
        std::list<Edge*>* list = this->digraph->getAdjList(v);
        for (std::list<Edge*>::iterator it = list->begin(); it != list->end(); ++it) {
            Edge* edge = *it;
            int flow = 0;
            EdgeInfo *edgeInfo = new EdgeInfo(edge, flow, edge->getCapacity());
            this->edgeMap[edge] = edgeInfo;
        }
    }
}

EdgeInfo* Flow::getEdgeInfo(Edge *edge) {
    return this->edgeMap[edge];
}

Flow::~Flow() {
    for (map<Edge*,EdgeInfo*>::iterator it = this->edgeMap.begin(); it != this->edgeMap.end(); ++it) {
        delete it->second;
    }
}