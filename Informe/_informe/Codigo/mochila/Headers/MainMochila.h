#ifndef TRABAJOPRACTICO2_MAINMOCHILA_H
#define TRABAJOPRACTICO2_MAINMOCHILA_H
#include <iostream>
#include "Parser.h"
#include "Mochila.h"
#include <list>
#include <algorithm>
using namespace std;

class MainMochila {
public:
    string rutaEasy1= "./mochila/files/knapPI_1_50_1000.csv";
    string rutaEasy2= "./mochila/files/knapPI_2_50_1000.csv";
    string rutaEasy3= "./mochila/files/knapPI_3_50_1000.csv";
    string rutaEasy4= "./mochila/files/knapPI_4_50_1000.csv";
    string rutaEasy5= "./mochila/files/knapPI_5_50_1000.csv";
    string rutaEasy6= "./mochila/files/knapPI_6_50_1000.csv";
    string rutaEasy7= "./mochila/files/knapPI_9_50_1000.csv";

    // Mochila test hard instances
    string rutaHard1= "./mochila/files/knapPI_16_100_1000.csv";
    string rutaHard2 = "./mochila/files/knapPI_16_500_1000.csv";
    string rutaHard3 = "./mochila/files/knapPI_16_1000_1000.csv";

    MainMochila() {

    }

    void _testAlgorithm(string fileName) {
        Parser* parser = new Parser();
        vector<Stage>* lista = parser->getListOfStages(fileName);

        for (int i = 0; i < lista->size(); i++) {
            Stage stage = lista->at(i);
            Mochila* mochila = new Mochila(stage);
            int solution = mochila->computarMochila();

            if (solution != stage.optimo) {
                throw std::string("Error no coincide el optimo en el stage:") + stage.name;
            }

            delete mochila;
        }


        delete parser;
        delete lista;

    }

    void testAlgorithm() {
        vector<string> files;
        files.push_back(rutaEasy1);
        files.push_back(rutaEasy2);
        files.push_back(rutaEasy3);
        //files.push_back(rutaEasy4);
        //files.push_back(rutaEasy5);
        //files.push_back(rutaEasy6);
        //files.push_back(rutaEasy7);

        for (int i = 0; i < files.size(); i ++) {
            string file = files.at(i);
            this->_testAlgorithm(file);
        }
    }

    void _testExecutionTime(string fileName) {
        Parser* parser = new Parser();
        vector<Stage>* lista = parser->getListOfStages(fileName);
        clock_t start_time;
        clock_t stop_time;
        string outputFileName = fileName + "_results.csv";
        ofstream outputFile(outputFileName.c_str());
        outputFile << "Corrida,Clocks,Tiempo" << std::endl;

        for (int i = 0; i < lista->size(); i++) {
            Stage stage = lista->at(i);
            start_time = clock();
            Mochila* mochila = new Mochila(stage);
            int solution = mochila->computarMochila();
            stop_time = clock();

            double time = (double(stop_time-start_time)/CLOCKS_PER_SEC);
            outputFile << i << "," << stop_time-start_time << "," << time << std::endl;

            delete mochila;
        }

        outputFile.close();
        delete parser;
        delete lista;

    }

    void testExecutionTime() {
        _testExecutionTime(rutaHard1);
        //_testExecutionTime(rutaHard2);
        //_testExecutionTime(rutaHard3);

    }

    int run() {
        testAlgorithm();
        testExecutionTime();
    }

};


#endif //TRABAJOPRACTICO2_MAINMOCHILA_H
