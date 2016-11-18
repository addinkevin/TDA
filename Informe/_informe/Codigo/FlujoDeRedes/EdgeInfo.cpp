#include "EdgeInfo.h"

EdgeInfo::EdgeInfo(Edge *edge, int flow, int capacity) {
    this->edge = edge;
    this->flow = flow;
    this->capacity = capacity;
}

int EdgeInfo::getCapacity() {
    return this->capacity;
}

int EdgeInfo::getFlow() {
    return this->flow;
}

int EdgeInfo::getResidualCapacity() {
    return this->capacity - this->flow;
}

void EdgeInfo::setFlow(int newFlow) {
    this->flow = newFlow;
}

