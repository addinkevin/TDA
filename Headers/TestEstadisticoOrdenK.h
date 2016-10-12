//
// Created by kevin on 10/12/16.
//

#ifndef TDA_TESTESTADISTICOORDENK_H
#define TDA_TESTESTADISTICOORDENK_H

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include "Utils.h"

class TestEstadisticoOrdenK {
public:
    void test(bool condition, std::string msgError) {
        if (!condition) {
            std::cout << "Error:" << msgError;
        }
    }

    void testAlgorithm(int (*algorithm)(vector<int>*, int), vector<int>* array, int k, std::string descr) {
        //std::random_shuffle(array->begin(), array->end());
        int result = algorithm(array,k);

        test(result == k, "Error al correr " + descr + ". Se esperaba " + std::to_string(k) + " se obtuvo: " + std::to_string(result));
    }

    std::vector<int> crearVector(int vectorSize) {
        std::vector<int> vector;
        for (int i = 0 ; i < vectorSize; i++) {
            vector.push_back(i); // Arreglo desde 0 hasta vectorSize-1.
        }
        return vector;
    }

    void testAll() {
        std::srand ( unsigned ( std::time(0) ) );
        int vectorSize = 1000;
        std::vector<int> vector;

        for (int i = 0; i < 100; i++) {
            int k = std::rand()% vectorSize;


            vector = crearVector(vectorSize);
            testAlgorithm(Utils::bruteForce, &vector, k, "Fuerza bruta");
            vector = crearVector(vectorSize);
            testAlgorithm(Utils::orderAndSelect,&vector, k, "Order and select");
            vector = crearVector(vectorSize);
            testAlgorithm(Utils::kSelection,&vector, k, "k selection");
            vector = crearVector(vectorSize);
            testAlgorithm(Utils::kHeapSort,&vector, k, "k heapsort");
            vector = crearVector(vectorSize);
            testAlgorithm(Utils::heapSelect,&vector, k, "heap select");

            vector = crearVector(vectorSize);
            testAlgorithm(Utils::quickSelect,&vector, k, "quick select");

        }
    }
};


#endif //TDA_TESTESTADISTICOORDENK_H
