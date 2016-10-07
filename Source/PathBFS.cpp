/*
 * PathBFS.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: gatti2602
 */

#include "../Headers/PathBFS.h"

#include <queue>

using namespace std;

PathBFS::PathBFS(Digraph* g, int source, int dest ) : Path(g, source, dest ){

	marked = new bool[g->getVertices()];
	distance = new int[g->getVertices()];
	edgeTo = new Edge*[g->getVertices()];

	for(int i=0;i<g->getVertices();i++) {
		distance[i] = Path::NO_PATH;        //Inicializo distancias con distancia infinito
	}

	queue<int> queue;

	marked[this->source] = true;
	distance[this->source] = 0;

	queue.push(this->source);	//arranco desde el source

	//Mientras haya un vertice pendiente y no se haya encontrado el destino
	while(!queue.empty() && !marked[this->dest]){
		int v = queue.front();
		queue.pop();
		list<Edge*>* adjList = g->getAdjList(v);

		//Barro la lista de adyacencia
		for (std::list<Edge*>::iterator it=adjList->begin(); it != adjList->end(); ++it){
			    int vert = (*it)->getDest();

			    if(!marked[vert]){
			    	distance[vert] = distance[v] + 1; // Acumulo la distancia desde el origen hasta el vertice
			    	marked[vert]= true;
			    	queue.push(vert);
			    	edgeTo[vert] = *it;	//guardo el camino por el que fui
			    }
			}
	}

}

bool PathBFS::visited(int v){
	return marked[v];

}

int PathBFS::distanceTo(int v){
	return distance[v];

}

std::list<Edge*> PathBFS::pathTo(int v){
	list<Edge*> aList;
	if(!marked[v])
		return aList; // Lista vacia

	for(int i = v;i!= this->source;i=edgeTo[i]->getSource())
		aList.push_back(edgeTo[i]);

	aList.push_back(edgeTo[this->source]); // Creo que esta no hace falta.

	// TODO: Invertir el orden de la lista.
	return aList;
}

PathBFS::~PathBFS() {
	delete marked;
	delete edgeTo;
	delete distance;
}

