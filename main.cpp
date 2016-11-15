#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Viajante/ParserTSPFile.h"
#include "Viajante/Types.h"
#include "Viajante/TSPTest.h"
#include "mochila/Headers/Mochila.h"

using namespace std;

void printMatrix(vector<vector<CostInt>>* matrix) {
    for (vector<vector<CostInt>>::iterator it = matrix->begin(); it != matrix->end(); ++it) {
        vector<CostInt> items = *it;
        for (vector<CostInt>::iterator it2 = items.begin(); it2 != items.end(); ++it2) {
            CostInt x = *it2;
            std::cout << int(x) << "\t";
        }
        std::cout << std::endl;
    }
}

void printSolution(vector<VertexInt>* solutionList) {
    for (vector<VertexInt>::iterator it = solutionList->begin(); it != solutionList->end(); ++it) {
        VertexInt x = *it;
        std::cout << int(x) << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    try{
        std::cout << "Hello, World!" << std::endl;

        /*
        ParserTSPFile parserTSPFile("./Viajante/files/tsp2.txt", "./Viajante/files/tsp2_s.txt");
        vector<vector<CostInt>>* matrix = parserTSPFile.getMatrix();
        //printMatrix(matrix);

        vector<VertexInt>* solutionList = parserTSPFile.getSolutionList();

        printSolution(solutionList);
         */

        TSPTest test;
        //test.runExample("./Viajante/files/prueba.txt", "./Viajante/files/prueba_s.txt");
        //test.runExample("./Viajante/files/tsp2.txt", "./Viajante/files/tsp2_s.txt");
        Mochila mochila;

    } catch(string & error) {
        std::cout << "***ERROR***: "<< error << endl;
    }
    return 0;
}
