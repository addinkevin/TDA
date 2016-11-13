//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_FORDFULKENSON_H
#define TRABAJOPRACTICO2_FORDFULKENSON_H

#include <vector>
#include "Edge.h"
#include "Digraph.h"
#include "Flow.h"
#include "ParserNetworkFlow.h"

using namespace std;

class FordFulkerson {
private:
    ParserNetworkFlow *parser;
    Flow* flow;
    vector<int> setS;
    vector<int> setT;

    int bottleneck(vector<Edge*> pathInResidualGraph);

    void augment(vector<Edge*> pathInResidualGraph);

    bool isEdgeForward(Edge* edge);

    Edge *getEdgeInG(Edge *edgeInGResidual);

    vector<Edge *> getPathST();

    void calculateMinCut();
public:

    FordFulkerson(ParserNetworkFlow* parser);
    ~FordFulkerson();

    void maxFlow();

    vector<int> getSetS();
    vector<int> getSetT();

    vector<int> getProjects();
    vector<int> getAreas();

};


#endif //TRABAJOPRACTICO2_FORDFULKENSON_H
