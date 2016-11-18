#ifndef TRABAJOPRACTICO2_TSPTEST_H
#define TRABAJOPRACTICO2_TSPTEST_H

#include "Types.h"
#include "ParserTSPFile.h"
#include "TSPRecursive.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TSPTest {
public:
    CostInt calculateCost(vector<vector<CostInt>>* matrixCost, vector<VertexInt>* list) {
        CostInt cost = 0;
        for (unsigned int i = 0; i < list->size() - 1 ; i++) {
            VertexInt x = list->at(i);
            VertexInt y = list->at(i+1);
            cost += matrixCost->at(x).at(y);
        }

        return cost;
    }

    bool checkPathList(vector<VertexInt>* expectedList, vector<VertexInt>* actualList) {
        if (expectedList->size() != actualList->size()) {
            return false;
        }

        // Puede que los recorridos estén invertidos, pero valen igual en el caso de que la matriz sea simetrica.
        bool toReturn = true;
        for (unsigned int i = 0; i < expectedList->size(); i++) {
            if (expectedList->at(i) != actualList->at(i)) {
                toReturn = false;
                break;
            }
        }

        if (toReturn) return true;

        toReturn = true;
        unsigned int size = expectedList->size();
        for (unsigned int i = 0; i < expectedList->size(); i++) {
            if (expectedList->at(i) != actualList->at(size-i-1)) {
                toReturn = false;
                break;
            }
        }

        return toReturn;
    }

    void printRecorrido(string msg, vector<VertexInt>* pathList) {
        std::cout << msg << std::endl;
        for (unsigned int i = 0; i < pathList->size(); i++) {
            VertexInt vertexInt = pathList->at(i);
            std::cout << int(vertexInt) << "\t";
        }
        std::cout << std::endl;
    }

    void runExample(string matrixFileName, string solutionFileName) {
        ParserTSPFile parserTSPFile(matrixFileName, solutionFileName);
        vector<vector<CostInt>>* matrix = parserTSPFile.getMatrix();
        vector<VertexInt>* expectedList = parserTSPFile.getSolutionList();
        CostInt expectedCost = calculateCost(matrix, expectedList);

        TSPRecursive* tspRecursive = new TSPRecursive(matrix, 0);

        pair<CostInt, vector<VertexInt>*> par = tspRecursive->run();

        if (expectedCost != par.first) {
            delete tspRecursive;
            delete matrix;
            delete expectedList;
            delete par.second;
            throw string("Error al coincidir los costos en " + matrixFileName + ". Se esperaba ") \
                    + to_string(expectedCost) + string(" y se obtuvo: ") + to_string(par.first);
        }

        if (!checkPathList(expectedList, par.second)) {
            printRecorrido("Esperado", expectedList);
            printRecorrido("Obtenido", par.second);

            delete tspRecursive;
            delete matrix;
            delete expectedList;
            delete par.second;
            throw string("No hubo coincidencia en los recorridos.");
        }

        std::cout << "Ejecucion de " << matrixFileName << " exitosa." << std::endl;

        delete tspRecursive;
        delete matrix;
        delete expectedList;
        delete par.second;
    }

};


#endif //TRABAJOPRACTICO2_TSPTEST_H
