//
// Created by kevin on 10/7/16.
//

#ifndef TDA_TESTGRAPHALGORITMS_H
#define TDA_TESTGRAPHALGORITMS_H

#include <iostream>

class TestGraphAlgorithms {
public:

    void test(bool condition, std::string msgError) {
        if (!condition) {
            throw std::string("Error al probar") + msgError;
        }
    }

    void testCreateGraphFromFile();

    void testPriorityQueue();

    void testSearchWithHeuristic();

    void testAll() {
        testCreateGraphFromFile();
        testPriorityQueue();

        std::cout << "All tests OK" << std::endl;
    }
};

#endif //TDA_TESTGRAPHALGORITMS_H
