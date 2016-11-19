
#include "Path.h"

Path::Path(Digraph* g, int source, int dest){
	this->g = g;
	this->source = source;
	this->dest = dest;
	this->marked = new bool[g->getVertices()];
	this->distance = new double[g->getVertices()];
	this->edgeTo = new Edge*[g->getVertices()];

	for(int i=0; i < g->getVertices(); i++) {
		this->marked[i] = false;
		this->distance[i] = Path::NO_PATH;
		this->edgeTo[i] = NULL;
	}
}

Path::~Path() {
	delete marked;
	delete edgeTo;
	delete distance;
}

bool Path::visited(int v) {
	return this->marked[v];
}

std::list<Edge *> Path::pathTo(int v) {
	std::list<Edge*> aList;
	if (!this->marked[v]) {
		return aList; // Lista vacia
	}

	for(int i = v; i!= this->source; i=edgeTo[i]->getSource()) {
		aList.push_back(edgeTo[i]);
	}

	aList.reverse();

	return aList;
}

int Path::getSource() {
	return this->source;
}

int Path::getDest() {
	return this->dest;
}

std::list<int> Path::getVertexPath(int v) {
	std::list<int> aList;
	if (!this->marked[v]) {
		return aList; // Lista vacia
	}

	aList.push_back(v);
	for(int i = v; i!= this->source; i=this->edgeTo[i]->getSource()) {
		aList.push_back(this->edgeTo[i]->getSource());
	}

	aList.reverse();

	return aList;
}

double Path::distanceTo(int v) {
	return this->distance[v];
}



