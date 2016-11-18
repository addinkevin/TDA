
#ifndef DIGRAPH_H_
#define DIGRAPH_H_
#include <vector>
#include <list>
#include <string>
#include "Edge.h"
#include <iostream>
#include <stdlib.h>

class Digraph {
private:
	//Cantidad de vertices del Grafo
	int v, e;
	//Lista de adyacencia del grafo
	std::vector<std::list<Edge*>*> adjList;

	void initGraph(int vertices);

public:
	Digraph(int vertices);

	int getVertices();
	int getEdges();
	std::list<Edge*>* getAdjList(int v);
	std::list<int> getAdj(int v);
	void addEdge(int source, int dest, int capacity);
    void addEdge(Edge* edge);

	~Digraph();
};

#endif /* DIGRAPH_H_ */
