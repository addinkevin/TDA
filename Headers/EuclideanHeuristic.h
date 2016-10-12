//
// Created by kevin on 10/11/16.
//

#ifndef TDA_EUCLIDEANHEURISTIC_H
#define TDA_EUCLIDEANHEURISTIC_H

#include <map>
#include "Heuristic.h"
#include "Vertex.h"

class EuclideanHeuristic : public Heuristic {
private:
    std::map<int,Vertex> vertexMap;
    int source;
    int dest;

    static double FACTOR;
public:
    EuclideanHeuristic(std::map<int,Vertex> vertexMap, int source, int dest);
    virtual double getCost(int v);
};

#endif //TDA_EUCLIDEANHEURISTIC_H
