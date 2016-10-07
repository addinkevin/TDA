//
// Created by kevin on 10/7/16.
//

#include <fstream>
#include "../Headers/TestGraphAlgorithms.h"
#include "../Headers/Digraph.h"

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
