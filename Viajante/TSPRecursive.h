//
// Created by kevin on 11/12/16.
//

#ifndef TRABAJOPRACTICO2_TSPRECURSIVE_H
#define TRABAJOPRACTICO2_TSPRECURSIVE_H

#include "Types.h"
#include <vector>
#include <utility>
#include <map>

using namespace std;

class TSPRecursive {
private:

    vector<vector<CostInt>>* matrix;
    VertexInt vertexCount;
    vector<map<SetInt, CostInt>>* memory;
    vector<map<SetInt, VertexInt>>* path;
    VertexInt initialVertex;

    SetInt getSetNumberWithOutVertex(SetInt setNumber, VertexInt vertexNumber);
    SetInt getSetNumberWithVertex(SetInt setNumber, VertexInt vertexNumber);

    vector<VertexInt>* createPathList(SetInt setNumber, VertexInt initialVertex);

    CostInt _run(VertexInt vertex, SetInt setNumber);

public:
    TSPRecursive(vector<vector<CostInt>>* matrix, VertexInt initialVertex);
    ~TSPRecursive();

    pair<CostInt, vector<VertexInt>*> run();

};


#endif //TRABAJOPRACTICO2_TSPRECURSIVE_H
