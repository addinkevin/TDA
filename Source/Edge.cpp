/*
 * Edge.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: gatti2602
 */

#include "../Headers/Edge.h"

Edge::Edge(int source, int dest, double weight) {
	this->source = source;
	this->dest = dest;
	this->weight = weight;
}

int Edge::getSource(){
	return this->source;
}

int Edge::getDest(){
	return this->dest;
}

double Edge::getWeight(){
	return this->weight;
}

Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

