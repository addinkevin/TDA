//
// Created by kevin on 10/7/16.
//

#include <fstream>
#include "../Headers/TestGraphAlgorithms.h"
#include "../Headers/Digraph.h"
#include "../Headers/PriorityQueue.h"
#include "../Headers/SearchWithHeuristic.h"

void TestGraphAlgorithms::testCreateGraphFromFile() {
    std::string fileName = "/tmp/archivoGrafoPrueba.txt";
    std::ofstream file(fileName);

    file << "10" << std::endl;
    file << "1,2,3" << std::endl;
    file << "4,5,6" << std::endl;
    file << "7,8,9.5" << std::endl;

    file.close();

    Digraph* digraph = new Digraph(fileName);

    test(digraph->getVertices() == 10, "No tiene 10 vertices");
    test(digraph->getEdges() == 3, "No tiene 3 aristas");
    test(digraph->getAdj(1).front() == 2, "Error arista 1");
    test(digraph->getAdj(7).front() == 8, "Error arista 3");
    test(digraph->getAdjList(1)->front()->getWeight() == 3, "Error peso arista 1");
    test(digraph->getAdjList(7)->front()->getWeight() == 9.5, "Error peso arista 3");

    delete digraph;
}

void TestGraphAlgorithms::testPriorityQueue() {
    PriorityQueue priorityQueue;

    test(priorityQueue.empty(), "Error al probar empty");

    priorityQueue.push(1,10);
    priorityQueue.push(2,50);
    priorityQueue.push(3, 30);

    test(priorityQueue.top().first == 1, "Error al dar el de mayor prioridad, 1");
    priorityQueue.pop();
    test(priorityQueue.top().first == 3, "Error al dar el de mayor prioridad, 3");
    priorityQueue.pop();
    test(priorityQueue.top().first == 2, "Error al dar el de mayor prioridad, 2");
}

void TestGraphAlgorithms::testSearchWithHeuristic() {
    // TODO
}


