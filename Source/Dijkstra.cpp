//
// Created by kevin on 10/8/16.
//

#include "../Headers/Dijkstra.h"
#include "../Headers/PriorityQueue.h"

Dijkstra::Dijkstra(Digraph *g, int source, int dest) : Path(g, source, dest) {
    this->marked = new bool[g->getVertices()];
    this->distance = new double[g->getVertices()];
    this->edgeTo = new Edge*[g->getVertices()];

    for(int i=0; i < g->getVertices(); i++) {
        this->marked[i] = false;
        this->distance[i] = Path::NO_PATH;        // Inicializo distancias con distancia infinito
    }

    this->marked[this->source] = true;
    this->distance[this->source] = 0;

    PriorityQueue priorityQueue;
    priorityQueue.push(this->source, 0 );

    while (!priorityQueue.empty()) {
        std::pair<int,double> pairObject = priorityQueue.pop();
        int currentVertex = pairObject.first;
        double priority = pairObject.second;

        if (currentVertex == this->dest) {
            break;
        }

        std::list<Edge*>* adjList = g->getAdjList(currentVertex);

        for (std::list<Edge*>::iterator it=adjList->begin(); it != adjList->end(); ++it){
            int nextVert = (*it)->getDest();
            double weight = (*it)->getWeight();

            double newCost = this->distance[currentVertex] + weight;

            if (!this->marked[nextVert] || newCost < this->distance[nextVert]) {
                this->marked[nextVert] = true;
                this->distance[nextVert] = newCost;
                priority = newCost;
                priorityQueue.push(nextVert, priority);
                edgeTo[nextVert] = *it;
            }
        }
    }
}

Dijkstra::~Dijkstra() {
    delete marked;
    delete edgeTo;
    delete distance;
}

bool Dijkstra::visited(int v) {
    return this->marked[v];
}

double Dijkstra::distanceTo(int v) {
    return this->distance[v];
}

std::list<Edge *> Dijkstra::pathTo(int v) {
    std::list<Edge*> aList;
    if (!marked[v]) {
        return aList; // Lista vacia
    }

    for(int i = v; i!= this->source; i=edgeTo[i]->getSource()) {
        aList.push_back(edgeTo[i]);
    }

    aList.reverse();

    return aList;
}