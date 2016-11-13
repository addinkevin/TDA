//
// Created by kevin on 11/12/16.
//

#include "TSPRecursive.h"

TSPRecursive::TSPRecursive(vector<vector<CostInt>> *matrix, VertexInt initialVertex) {
    this->matrix = matrix;
    this->vertexCount = this->matrix->size();

    this->memory = new vector<map<SetInt, CostInt>>();

    this->path = new vector<map<SetInt, VertexInt>>();

    for (unsigned int i = 0; i < this->vertexCount; i++) {
        this->memory->push_back(map<SetInt,CostInt>());
        this->path->push_back(map<SetInt,VertexInt>());
    }

    this->initialVertex = initialVertex;
}

TSPRecursive::~TSPRecursive() {
    delete this->memory;
    delete this->path;
}


CostInt TSPRecursive::_run(VertexInt vertex, SetInt setNumber) {

    if (setNumber == 0) {
        return this->matrix->at(vertex).at(this->initialVertex);
    } else if (this->memory->at(vertex).count(setNumber)) {
        // Ya fue calculado
        return this->memory->at(vertex).at(setNumber);
    }

    CostInt minCost = (CostInt)(-1);
    VertexInt vertexMin;

    SetInt copySetNumber = setNumber;

    for (VertexInt u = 0; u < this->vertexCount; u++) {
        unsigned int n = copySetNumber & 1;
        if (n == 1) {
            // Proceso el vertex u
            CostInt result = this->matrix->at(vertex).at(u) +
                             this->_run(u, this->getSetNumberWithOutVertex(setNumber, u));

            if (result < minCost) {
                minCost = result;
                vertexMin = u;
            }
        }
        copySetNumber = copySetNumber >> 1; // setNumber /= 2;
    }

    this->memory->at(vertex)[setNumber] = minCost;
    this->path->at(vertex)[setNumber] = vertexMin;

    return minCost;

}

vector<VertexInt> *TSPRecursive::createPathList(SetInt setNumber, VertexInt initialVertex) {
    vector<VertexInt>* pathList = new vector<VertexInt>();
    pathList->push_back(initialVertex);
    VertexInt actualVertex = initialVertex;

    for (unsigned int i = 0 ; i < this->vertexCount - 1 ; i++) {
        VertexInt nextVertex = this->path->at(actualVertex).at(setNumber);
        pathList->push_back(nextVertex);
        setNumber = this->getSetNumberWithOutVertex(setNumber, nextVertex);
        actualVertex = nextVertex;
    }

    pathList->push_back(initialVertex);
    return pathList;
}

SetInt TSPRecursive::getSetNumberWithVertex(SetInt setNumber, VertexInt vertexNumber) {
    return setNumber + (1<<vertexNumber);
}

SetInt TSPRecursive::getSetNumberWithOutVertex(SetInt setNumber, VertexInt vertexNumber) {
    return setNumber - (1<< vertexNumber);
}

pair<CostInt, vector<VertexInt> *> TSPRecursive::run() {
    SetInt setNumber = (1 << this->vertexCount) - 1;
    CostInt cost = this->_run(this->initialVertex, this->getSetNumberWithOutVertex(setNumber, initialVertex));
    vector<VertexInt>* pathList = this->createPathList(this->getSetNumberWithOutVertex(setNumber, initialVertex), initialVertex);

    return pair<CostInt, vector<VertexInt>*>(cost, pathList);
}
