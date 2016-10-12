//
// Created by kevin on 10/11/16.
//

#include "../Headers/EuclideanHeuristic.h"

double EuclideanHeuristic::FACTOR = 1.0;

EuclideanHeuristic::EuclideanHeuristic(std::map<int, Vertex> vertexMap, int source, int dest) {
    this->source = source;
    this->dest = dest;
    this->vertexMap = vertexMap;
}

double EuclideanHeuristic::getCost(int v) {
    Vertex destVertex = this->vertexMap.at(this->dest);
    Vertex actualVertex = this->vertexMap.at(v);

    int dx = abs(destVertex.x - actualVertex.x);
    int dy = abs(destVertex.y - actualVertex.y);

    return FACTOR * (dx*dx + dy*dy);
}
