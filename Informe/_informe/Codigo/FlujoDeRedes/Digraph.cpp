
#include <fstream>
#include <sstream>
#include "Digraph.h"

using namespace std;


Digraph::Digraph(int vertices) {
	this->initGraph(vertices);
}

void Digraph::initGraph(int vertices) {
	this->v = vertices;
	this->e = 0;
	//Reservo espacio para cada una de las listas de adyacencia de cada vertice
	this->adjList.reserve(vertices);

	for(int i=0; i<vertices;i++ ){
		this->adjList.push_back(new std::list<Edge*>);
	}
}


int Digraph::getVertices(){
	return this->v;
}

int Digraph::getEdges(){
	return this->e;
}

list<Edge*>* Digraph::getAdjList(int v){
	return this->adjList[v];
}

list<int> Digraph::getAdj(int v){
	list<Edge*>* listVert = this->adjList[v];
	list<int> vert;

	//Devuelvo los vertices alcanzados por las aristas que salen de v
	for (std::list<Edge*>::iterator it=listVert->begin(); it != listVert->end(); ++it){
	    vert.push_back((*it)->getDest());
	}

	return vert;
}

void Digraph::addEdge(int source, int dest, int capacity) {
	Edge* edge = new Edge(source,dest, capacity);
    this->addEdge(edge);
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

void Digraph::addEdge(Edge *edge) {
    this->adjList[edge->getSource()]->push_back(edge);
    this->e ++;
}
