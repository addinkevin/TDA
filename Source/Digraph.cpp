/*
 * Digraph.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: gatti2602
 */

#include "../Headers/Digraph.h"

using namespace std;


Digraph::Digraph(int vertices) {
	this->v = vertices;
	//Reservo espacio para cada una de las listas de adyacencia de cada vertice
	this->adjList.reserve(vertices);

	for(int i=0; i<vertices;i++ ){
		this->adjList.push_back(new std::list<Edge*>);
	}

}

int Digraph::getVertices(){
	return this->v;
}

list<Edge*>* Digraph::getAdjList(int v){
	return this->adjList[v];
}

void Digraph::addEdge(int source, int dest, int weight){
	Edge* e = new Edge(source,dest,weight);
	this->adjList[source]->push_back(e);
}


Digraph::~Digraph() {
	for(int i=0;i<this->v;i++){
		list<Edge*>* list = this->adjList[i];
		while(!list->empty()){
			//Se elimina cada una de las aristas instanciadas
			delete(list->front());
			list->pop_front();
		}
		//Se elimina la lista de adyacencia para ese vertice
		delete(list);
	}
}

