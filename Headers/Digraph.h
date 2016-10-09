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
#include <string>
#include "../Headers/Edge.h"
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

	/*
	 * Crea un digrafo a partir de un archivo.
	 * Formato del archivo:
	 * 	numero de vertices
	 * 	v1,v2, p
	 * 	...
	 * */
	Digraph(std::string fileName);

	int getVertices();
	int getEdges();
	std::list<Edge*>* getAdjList(int v);
	std::list<int> getAdj(int v);
	void addEdge(int source, int dest, double weight);

	~Digraph();
};

#endif /* DIGRAPH_H_ */
