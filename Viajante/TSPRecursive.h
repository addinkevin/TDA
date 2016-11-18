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

    vector<VertexInt>* createPathList(SetInt setNumber, VertexInt initialVertex);

    CostInt _run(VertexInt vertex, SetInt setNumber);

public:
    /*
     * vector<vector<CostInt>>* matrix:
     *      Matriz de costos no negativos, se asume que es una matriz cuadrada N*N, N = size(matrix)
     *
     * VertexInt initialVertex:
     *      Vertice inicial para la ejecución del algoritmo
     *
     */
    TSPRecursive(vector<vector<CostInt>>* matrix, VertexInt initialVertex);
    ~TSPRecursive();

    /*
     * Lleva a cabo la ejecución del algoritmo.
     * Se obtiene un par pair<CostInt, vector<VertexInt>*>
     * que contiene el costo de recorrer todas las ciudades
     * (suma de los pesos de las aristas recorridas)
     * y un vector que contiene los vertices en orden para
     * realizar el recorrido y alcanzar dicho costo.
     */
    pair<CostInt, vector<VertexInt>*> run();

};


#endif //TRABAJOPRACTICO2_TSPRECURSIVE_H
