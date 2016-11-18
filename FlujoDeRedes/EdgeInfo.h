//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_EDGEINFO_H
#define TRABAJOPRACTICO2_EDGEINFO_H


#include "Edge.h"

class EdgeInfo {
private:
    Edge* edge;
    int flow;
    int capacity;
public:
    EdgeInfo(Edge* edge, int flow, int capacity);

    int getCapacity();
    int getFlow();
    int getResidualCapacity();

    void setFlow(int newFlow);

};


#endif //TRABAJOPRACTICO2_EDGEINFO_H
