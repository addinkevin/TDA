/*
 * Digraph.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: gatti2602
 */

#include <fstream>
#include <sstream>
#include "../Headers/Digraph.h"

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

void Digraph::addEdge(int source, int dest, int weight){
	Edge* e = new Edge(source,dest,weight);
	this->adjList[source]->push_back(e);
	this->e ++;
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


Digraph::Digraph(std::string fileName) {
	std::ifstream file(fileName.c_str());
	if (!file.is_open()) {
		throw std::string("Error al abrir el archivo para levantar el grafo") + fileName;
	}

	std::string line;

	std::getline(file, line);
	int vertexCount = atoi(line.c_str());

	this->initGraph(vertexCount);

	while (std::getline(file,line)) {
        if (line.empty()) break;

		std::istringstream stringStream(line);
		std::string field;
		getline(stringStream, field, ',');
		int vertexFrom = atoi(field.c_str());
		getline(stringStream, field, ',');
		int vertexTo = atoi(field.c_str());
		getline(stringStream, field, ',');
		int weight = atoi(field.c_str());

		this->addEdge(vertexFrom, vertexTo, weight);
	}

	file.close();
}


