//
// Created by kevin on 10/7/16.
//

#include "../Headers/SearchWithHeuristic.h"
#include "../Headers/PriorityQueue.h"

SearchWithHeuristic::SearchWithHeuristic(Digraph *g, int source, int dest, Heuristic& heuristic) : Path(g, source, dest) {

    for(int i=0; i < g->getVertices(); i++) {
        marked[i] = false;
        distance[i] = Path::NO_PATH;        // Inicializo distancias con distancia infinito
    }

    PriorityQueue priorityQueue;

    marked[this->source] = true;
    distance[this->source] = 0;

    priorityQueue.push(this->source, 0); // Arranco desde el source.

    //Mientras haya un vertice pendiente y no se haya encontrado el destino
    while(!priorityQueue.empty() && !marked[this->dest]){
        std::pair<int,double> pairObject = priorityQueue.pop();
        int v = pairObject.first;

        std::list<Edge*>* adjList = g->getAdjList(v);

        //Barro la lista de adyacencia
        for (std::list<Edge*>::iterator it=adjList->begin(); it != adjList->end(); ++it){
            int vert = (*it)->getDest();

            if(!marked[vert]){
                distance[vert] = distance[v] + 1; // Acumulo la distancia desde el origen hasta el vertice
                marked[vert]= true;
                priorityQueue.push(vert, heuristic.getCost(vert));
                edgeTo[vert] = *it;	//guardo el camino por el que fui
            }
        }
    }

}

SearchWithHeuristic::~SearchWithHeuristic() {

}