
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
#include "../Headers/ExactHeuristic.h"
#include "../Headers/OptimisticHeuristic.h"
#include "../Headers/PessimisticHeuristic.h"
#include "../Headers/TestGraphAlgorithms.h"

#include <iostream>

using namespace std;


int runK() {
	int n = 10000;
	int k = 0;
	int kMin;

	//create differents arrays with the same k value
	for(int i=0; i < 10; i++){
		vector<int> array = Utils::get()->createArray(n);
        vector<int> arrays[6];
        for (int j = 0; j < 6; j++) {
            arrays[j] = vector<int>(array);
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

	return 0;
}


void dijkstra() {
    MapParser* mapParser;
    Digraph *digraph;
    Path* path;

    mapParser = new MapParser("./Grafos/Dijkstra/dijkstra1.txt");
    mapParser->drawGraph("./Grafos/Dijkstra/dijkstra1.svg");

    digraph = mapParser->createGraph();
    path = new Dijkstra(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex());
    mapParser->drawGraphResults("./Grafos/Dijkstra/dijkstra1Result.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    mapParser = new MapParser("./Grafos/Dijkstra/dijkstra2.txt");
    mapParser->drawGraph("./Grafos/Dijkstra/dijkstra2.svg");

    digraph = mapParser->createGraph();
    path = new Dijkstra(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex());
    mapParser->drawGraphResults("./Grafos/Dijkstra/dijkstra2Result.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;


}

void searchWithHeuristic() {
    MapParser* mapParser;
    Digraph *digraph;
    Path* path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo1.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo1.svg");

    digraph = mapParser->createGraph();
    ExactHeuristic exactHeuristic(digraph, mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), exactHeuristic);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo1HeuristicaExacta.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //

    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo3.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo3.svg");

    digraph = mapParser->createGraph();
    ExactHeuristic exactHeuristic2(digraph, mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), exactHeuristic2);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo3HeuristicaExacta.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo1.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo1.svg");

    digraph = mapParser->createGraph();
    OptimisticHeuristic optimisticHeuristic(digraph, mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), optimisticHeuristic);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo1HeuristicaOptimista.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo1.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo1.svg");

    digraph = mapParser->createGraph();
    PessimisticHeuristic pessimisticHeuristic(digraph, mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), pessimisticHeuristic);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo1HeuristicaPesimista.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo2.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo2.svg");

    digraph = mapParser->createGraph();
    ManhattanHeuristic manhattanHeuristic(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), manhattanHeuristic);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo2Manhattan.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo2.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo2.svg");

    digraph = mapParser->createGraph();
    EuclideanHeuristic euclideanHeuristic(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), euclideanHeuristic);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo2Euclidean.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo3.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo3.svg");

    digraph = mapParser->createGraph();
    ManhattanHeuristic manhattanHeuristic2(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), manhattanHeuristic2);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo3Manhattan.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/SearchWithHeuristic/grafo3.txt");
    mapParser->drawGraph("./Grafos/SearchWithHeuristic/grafo3.svg");

    digraph = mapParser->createGraph();
    EuclideanHeuristic euclideanHeuristic2(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new SearchWithHeuristic(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), euclideanHeuristic2);
    mapParser->drawGraphResults("./Grafos/SearchWithHeuristic/grafo3Euclidean.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

}

void aStar() {
    MapParser* mapParser;
    Digraph *digraph;
    Path* path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo1.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo1.svg");

    digraph = mapParser->createGraph();
    ExactHeuristic exactHeuristic(digraph, mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), exactHeuristic);
    mapParser->drawGraphResults("./Grafos/AStar/grafo1HeuristicaExacta.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo1.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo1.svg");

    digraph = mapParser->createGraph();
    ManhattanHeuristic manhattanHeuristic1(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), manhattanHeuristic1);
    mapParser->drawGraphResults("./Grafos/AStar/grafo1HeuristicaManhattan.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    mapParser = new MapParser("./Grafos/AStar/grafo1.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo1.svg");

    digraph = mapParser->createGraph();
    EuclideanHeuristic euclideanHeuristic1(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), euclideanHeuristic1);
    mapParser->drawGraphResults("./Grafos/AStar/grafo1HeuristicaEuclidean.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo1.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo1.svg");

    digraph = mapParser->createGraph();
    PessimisticHeuristic pessimisticHeuristic1(digraph, mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), pessimisticHeuristic1);
    mapParser->drawGraphResults("./Grafos/AStar/grafo1HeuristicaPesimista.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo2.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo2.svg");

    digraph = mapParser->createGraph();
    ManhattanHeuristic manhattanHeuristic(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), manhattanHeuristic);
    mapParser->drawGraphResults("./Grafos/AStar/grafo2Manhattan.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo2.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo2.svg");

    digraph = mapParser->createGraph();
    EuclideanHeuristic euclideanHeuristic(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), euclideanHeuristic);
    mapParser->drawGraphResults("./Grafos/AStar/grafo2Euclidean.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo3.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo3.svg");

    digraph = mapParser->createGraph();
    ManhattanHeuristic manhattanHeuristic2(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), manhattanHeuristic2);
    mapParser->drawGraphResults("./Grafos/AStar/grafo3Manhattan.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //
    mapParser = new MapParser("./Grafos/AStar/grafo3.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo3.svg");

    digraph = mapParser->createGraph();
    EuclideanHeuristic euclideanHeuristic2(mapParser->getVertexMap(), mapParser->getSourceVertex(), mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), euclideanHeuristic2);
    mapParser->drawGraphResults("./Grafos/AStar/grafo3Euclidean.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

    //

    mapParser = new MapParser("./Grafos/AStar/grafo3.txt");
    mapParser->drawGraph("./Grafos/AStar/grafo3.svg");

    digraph = mapParser->createGraph();
    ExactHeuristic exactHeuristic2(digraph, mapParser->getDestVertex());
    path = new AStar(digraph, mapParser->getSourceVertex(), mapParser->getDestVertex(), exactHeuristic2);
    mapParser->drawGraphResults("./Grafos/AStar/grafo3HeuristicaExacta.svg", *path);
    delete mapParser;
    delete digraph;
    delete path;

}

void generarGrafos() {
    dijkstra();
    searchWithHeuristic();
    aStar();
}

void testMain() {
    TestEstadisticoOrdenK testEstadisticoOrdenK;
    testEstadisticoOrdenK.testAll();

    TestGraphAlgorithms testGraphAlgorithms;
    testGraphAlgorithms.testAll();
}

int main() {
    generarGrafos();
    //runK();
    //testMain();
    return 0;
}
