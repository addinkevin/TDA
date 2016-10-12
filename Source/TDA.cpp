//============================================================================
// Name        : TDA.cpp
// Author      : Jorge
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Algorithms.h"
#include "../Headers/Digraph.h"
#include "../MapCreator/MapParser.h"
#include "../Headers/PathBFS.h"
#include "../Headers/Dijkstra.h"
#include "../Headers/AStar.h"
#include "../Headers/ManhattanHeuristic.h"
#include "../Headers/SearchWithHeuristic.h"
#include "../Headers/EuclideanHeuristic.h"
#include "../Headers/TestEstadisticoOrdenK.h"

#include <iostream>

using namespace std;

//Ejecuta funciones de Grafos (libera el main de tanto codigo)
void runGraphs(){
	cout << endl;
	cout << "[Algoritmos de Grafos]" << endl;
	Digraph* g = new Digraph(10);
	g->addEdge(1,2,3);
	cout << endl;
}

int main2() {
	int n = 1500;
	int k = 0;
	int kMin;

	//create differents arrays with the same k value
	for(int i=1; i <= 100; i++){
		n = 150 * i;
		vector<int> array = Utils::get()->createArray(n);
        vector<int> arrays[6];
        for (int i = 0; i < 6; i++) {
            arrays[i] = vector<int>(array);
        }

        // Fuerza bruta
        kMin = Algorithms::get()->bruteForce(&arrays[0],k);

        // Order and Select
        kMin = Algorithms::get()->orderAndSelect(&arrays[1],k);

        //KSelection
        kMin = Algorithms::get()->kSelection(&arrays[2],k);

        // k-heapsort
        kMin = Algorithms::get()->kHeapSort(&arrays[3],k);

        // HeapSelect
        kMin = Algorithms::get()->heapSelect(&arrays[4],k);

		//QuickSelect
		kMin = Algorithms::get()->quickSelect(&arrays[5],k);

	}

	//Save data into .csv file
	Algorithms::get()->recordData();

	//Free memory
	Algorithms::get()->~Algorithms();
	Utils::get()->~Utils();

	//runGraphs();
	return 0;
}

int main3() {
	MapParser mapParser("./MapCreator/MapExampleForAStar2");

	mapParser.drawGraph("salidaGrafo.svg");

    Digraph* digraph = mapParser.createGraph();

    //PathBFS pathBFS(digraph, mapParser.getSourceVertex(), mapParser.getDestVertex());
	Path* path;
	//path = new Dijkstra(digraph, mapParser.getSourceVertex(), mapParser.getDestVertex());
	//path = new PathBFS(digraph, mapParser.getSourceVertex(), mapParser.getDestVertex());
	ManhattanHeuristic manhattanHeuristic = ManhattanHeuristic(mapParser.getVertexMap(), mapParser.getSourceVertex(), mapParser.getDestVertex());
	EuclideanHeuristic euclideanHeuristic = EuclideanHeuristic(mapParser.getVertexMap(), mapParser.getSourceVertex(), mapParser.getDestVertex());
	//path = new AStar(digraph, mapParser.getSourceVertex(), mapParser.getDestVertex(), manhattanHeuristic);
	path = new SearchWithHeuristic(digraph, mapParser.getSourceVertex(), mapParser.getDestVertex(), manhattanHeuristic);

    mapParser.drawGraphResults("salidaGrafoResultadoBestSearch.svg", *path);

	delete path;
    delete digraph;

    return 0;
}

int main() {
    TestEstadisticoOrdenK testEstadisticoOrdenK;
    testEstadisticoOrdenK.testAll();
}
