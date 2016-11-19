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

    void testExecutionTime() {
        ofstream outputFile("./Viajante/files/tiempos.csv");

        string path = "./Viajante/files/filesForTiming/";
        clock_t start_time;
        clock_t stop_time;

        outputFile << "n, clocks" << std::endl;

        std::vector<string> files;
        files.push_back("tsp1");
        for (int i = 15; i <= 21; i++) {
            files.push_back("n"+to_string(i));
        }

        for (int i = 0; i < files.size(); i++ ) {
            ParserTSPFile* parserTSPFile = new ParserTSPFile(path+files[i]+".txt", path + "solution.txt");
            vector<vector<CostInt>>* matrix = parserTSPFile->getMatrix();
            std::cout << "Inicio Viajante:" << files[i] << " nodos." << std::endl;
            start_time = clock();
            TSPRecursive* tspRecursive = new TSPRecursive(matrix, 0);
            pair<CostInt, vector<VertexInt>*> par = tspRecursive->run();
            stop_time = clock();

            outputFile << files[i] << "," << stop_time - start_time << std::endl;
            std::cout << "Fin Viajante:" << files[i] << " nodos." << std::endl;

            delete parserTSPFile;
            delete matrix;
            delete tspRecursive;
            delete par.second;
        }

        outputFile.close();
    }

    void run() {
        TSPTest test;
        test.runExample("./Viajante/files/prueba.txt", "./Viajante/files/prueba_s.txt");
        test.runExample("./Viajante/files/tsp1.txt", "./Viajante/files/tsp1_s.txt");

        testExecutionTime();
    }
};


#endif //TRABAJOPRACTICO2_MAINVIAJANTE_H
