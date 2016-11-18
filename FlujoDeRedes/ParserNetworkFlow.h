//
// Created by kevin on 11/13/16.
//

#ifndef TRABAJOPRACTICO2_PARSERNETWORKFLOW_H
#define TRABAJOPRACTICO2_PARSERNETWORKFLOW_H

#include<string>
#include <fstream>
#include <vector>
#include "Digraph.h"
#include "Mapping.h"
#include "VertexInfo.h"

using namespace std;

class ParserNetworkFlow {
private:
    string fileName;

    void parse();
    vector<int> getAreaCosts(ifstream& file, int areasCount);
    int calculateTotalCapacity(vector<int> costs);
    void getProjects(ifstream& file, int count);
    pair<int,vector<int>> splitLine(string basic_string, char i);
    void createGraphs();

public:
    int areasCount;
    int projectsCount;
    vector<int> areaCosts;
    vector<int> profits;
    vector<vector<int>> projectDependencies;
    Mapping mapping;
    int infinityCapacity;
    map<int,VertexInfo> vertexMap;

    Digraph* graph;
    Digraph* residualGraph;

    ParserNetworkFlow(string fileName);

};


#endif //TRABAJOPRACTICO2_PARSERNETWORKFLOW_H
