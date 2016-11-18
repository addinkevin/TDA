
#include "Edge.h"

Edge::Edge(int source, int dest, int capacity) {
	this->source = source;
	this->dest = dest;
    this->capacity = capacity;
}

int Edge::getSource(){
	return this->source;
}

int Edge::getDest(){
	return this->dest;
}

int Edge::getCapacity() {
    return this->capacity;
}

Edge::~Edge() {
}

void Edge::setCapacity(int capacity) {
    this->capacity = capacity;
}
