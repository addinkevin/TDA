
#include "../Headers/PathBFS.h"

#include <queue>

using namespace std;

PathBFS::PathBFS(Digraph* g, int source, int dest ) : Path(g, source, dest ){

	for(int i=0;i<g->getVertices();i++) {
		marked[i] = false;
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
				double weight = (*it)->getWeight();

			    if(!marked[vert]){
			    	distance[vert] = distance[v] + weight; // Acumulo la distancia desde el origen hasta el vertice
			    	marked[vert]= true;
			    	queue.push(vert);
			    	edgeTo[vert] = *it;	//guardo el camino por el que fui
			    }
			}
	}

}

PathBFS::~PathBFS() {

}

