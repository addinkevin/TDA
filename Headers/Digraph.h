/*
 * Digraph.h
 *
 *  Created on: Oct 1, 2016
 *      Author: gatti2602
 */

#ifndef DIGRAPH_H_
#define DIGRAPH_H_
#include <vector>
#include <list>
#include "../Headers/Edge.h"
#include <iostream>

class Digraph {
private:
	//Cantidad de vertices del Grafo
	int v;
	//Lista de adyacencia del grafo
	std::vector<std::list<Edge*>*> adjList;


public:
	Digraph(int vertices);
	int getVertices();
	std::list<Edge*>* getAdjList(int v);
	void addEdge(int source, int dest, int weight);


	virtual ~Digraph();
};

#endif /* DIGRAPH_H_ */
