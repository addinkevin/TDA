//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_MAINFLUJODEREDES_H
#define TRABAJOPRACTICO2_MAINFLUJODEREDES_H

#include "ParserNetworkFlow.h"
#include "FordFulkerson.h"

class MainFlujoDeRedes {
public:

    void printVector(vector<int> v) {
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            int x = *it;
            std::cout << x << "\t";
        }
        std::cout << std::endl;
    }

    void printVectorDescription(ParserNetworkFlow& parserNetworkFlow, vector<int> v) {
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            int x = *it;
            std::cout << parserNetworkFlow.vertexMap[x].description << "\t";
        }
        std::cout << std::endl;
    }

    void runExample(string fileName) {
        std::cout << "-----" << std::endl;
        std::cout << ">Corrida del algoritmo sobre " << fileName << std::endl;
        ParserNetworkFlow parserNetworkFlow(fileName);
        FordFulkerson fordFulkerson(&parserNetworkFlow);

        fordFulkerson.maxFlow();

        std::cout << ">Conjuto S: " << std::endl;
        printVectorDescription(parserNetworkFlow, fordFulkerson.getSetS());

        std::cout << ">Conjunto T: " << std::endl;
        printVectorDescription(parserNetworkFlow, fordFulkerson.getSetT());

        std::cout << ">Projectos a realizar: " << std::endl;
        printVector(fordFulkerson.getProjects());

        std::cout << ">Areas a abonar: " << std::endl;
        printVector(fordFulkerson.getAreas());

        std::cout << ">Fin del algoritmo sobre " << fileName << std::endl;
        std::cout << "-----" << std::endl;
    }

    void run() {
        runExample("./FlujoDeRedes/files/trivialExample.txt");
        runExample("./FlujoDeRedes/files/trivialExample2.txt");
        runExample("./FlujoDeRedes/files/trivialExample3.txt");
        runExample("./FlujoDeRedes/files/trivialExample4.txt");
        runExample("./FlujoDeRedes/files/example1.txt");
        runExample("./FlujoDeRedes/files/example2.txt");

    }
};

#endif //TRABAJOPRACTICO2_MAINFLUJODEREDES_H
