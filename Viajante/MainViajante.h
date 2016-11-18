//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_MAINVIAJANTE_H
#define TRABAJOPRACTICO2_MAINVIAJANTE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ParserTSPFile.h"
#include "Types.h"
#include "TSPTest.h"

class MainViajante {
public:
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

    void run() {
        TSPTest test;
        test.runExample("./Viajante/files/prueba.txt", "./Viajante/files/prueba_s.txt");
        test.runExample("./Viajante/files/tsp1.txt", "./Viajante/files/tsp1_s.txt");
    }
};


#endif //TRABAJOPRACTICO2_MAINVIAJANTE_H
