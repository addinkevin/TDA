
#ifndef TDA_MANHATTANHEURISTIC_H
#define TDA_MANHATTANHEURISTIC_H


#include <map>
#include "Heuristic.h"
#include "Vertex.h"

class ManhattanHeuristic : public Heuristic {
private:
    std::map<int,Vertex> vertexMap;
    int source;
    int dest;

    static double FACTOR;
public:
    ManhattanHeuristic(std::map<int,Vertex> vertexMap, int source, int dest);
    virtual double getCost(int v);
};


#endif //TDA_MANHATTANHEURISTIC_H
