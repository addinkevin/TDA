//
// Created by kevin on 11/13/16.
//

#include "ParserNetworkFlow.h"
#include "Digraph.h"
#include <fstream>
#include <vector>
#include <sstream>

ParserNetworkFlow::ParserNetworkFlow(string fileName) {
    this->fileName = fileName;
    this->parse();
    this->createGraphs();
}

vector<int> ParserNetworkFlow::getAreaCosts(ifstream& file, int areasCount) {
    vector<int> costs;
    int i = 0;
    string line;
    while (getline(file,line)) {
        costs.push_back(stoi(line));
        i++;
        if (i == areasCount) break;
    }

    return costs;
}

int ParserNetworkFlow::calculateTotalCapacity(vector<int> costs) {
    int total = 0;
    for (int i = 0; i < costs.size(); i++) {
        total += costs.at(i);
    }

    return total;
}

void ParserNetworkFlow::getProjects(ifstream& file, int count) {
    int i = 0;
    string line;
    while (getline(file,line)) {
        pair<int,vector<int>> split = splitLine(line, ' ');
        this->profits.push_back(split.first);
        this->projectDependencies.push_back(split.second);

        i++;
        if (i == count) break;
    }
}


void ParserNetworkFlow::parse() {
    ifstream file = ifstream(this->fileName.c_str());
    if (!file.is_open()) {
        throw string("Error al abrir el archivo de flujo ") + this->fileName;
    }
    string line;

    getline(file, line);
    this->areasCount = stoi(line);

    getline(file,line);
    this->projectsCount = stoi(line);

    this->areaCosts = getAreaCosts(file, this->areasCount);
    this->infinityCapacity = calculateTotalCapacity(this->areaCosts) + 1;

    getProjects(file,this->projectsCount);

    file.close();
}

pair<int,vector<int>> ParserNetworkFlow::splitLine(string line, char delim) {
    vector<int > dependencies;
    stringstream ss;
    ss.str(line);
    string item;

    getline(ss, item, delim);
    int profit = stoi(item);

    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            dependencies.push_back(stoi(item));
        }
    }

    return pair<int,vector<int>>(profit, dependencies);
}

void ParserNetworkFlow::createGraphs() {
    this->graph = new Digraph(this->projectsCount + this->areasCount + 2);
    this->residualGraph = new Digraph(this->projectsCount + this->areasCount + 2);

    int sVertex = 0;
    int tVertex = this->projectsCount + this->areasCount + 1;

    for (int i = 0; i < this->projectsCount; i++) {
        // Agrego aristas s -> projects
        int projectVertex = i + 1;
        Edge* edgeG = new Edge(sVertex, projectVertex, this->profits.at(i));
        Edge* edgeForward = new Edge(sVertex, projectVertex, this->profits.at(i));
        Edge* edgeBackward = new Edge(projectVertex, sVertex, 0);
        edgeForward->edgeRef = edgeG;
        edgeForward->isFordward = true;
        edgeBackward->edgeRef = edgeG;

        this->mapping.mapEdgeGToResidualG[edgeG] = pair<Edge*,Edge*>(edgeForward, edgeBackward);
        VertexInfo vertexInfo("Projecto:" + to_string(i+1), i+1, true);
        this->vertexMap[projectVertex] = vertexInfo;

        this->graph->addEdge(edgeG);
        this->residualGraph->addEdge(edgeForward);
        this->residualGraph->addEdge(edgeBackward);
    }

    for (int i = 0; i < this->areasCount; i++) {
        // Agrego aristas areas-> t
        int areaVertex = this->projectsCount+i+1;
        Edge* edgeG = new Edge(areaVertex, tVertex, this->areaCosts.at(i));
        Edge* edgeForward = new Edge(areaVertex, tVertex, this->areaCosts.at(i));
        Edge* edgeBackward = new Edge(tVertex, areaVertex, 0);
        edgeForward->edgeRef = edgeG;
        edgeForward->isFordward = true;
        edgeBackward->edgeRef = edgeG;

        this->mapping.mapEdgeGToResidualG[edgeG] = pair<Edge*,Edge*>(edgeForward, edgeBackward);
        VertexInfo vertexInfo("Area:" + to_string(i+1), i+1, false);
        this->vertexMap[areaVertex] = vertexInfo;

        this->graph->addEdge(edgeG);
        this->residualGraph->addEdge(edgeForward);
        this->residualGraph->addEdge(edgeBackward);
    }

    for (int i = 0; i < this->projectsCount; i++) {
        // Agregado de dependencias
        int projectVertex = i + 1;
        vector<int> dependencies = this->projectDependencies.at(i);
        for (vector<int>::iterator it = dependencies.begin(); it != dependencies.end(); ++it) {
            int areaVertex = this->projectsCount + (*it); // Se asume que el archivo indica las areas a partir de 1.

            Edge* edgeG = new Edge(projectVertex, areaVertex, this->infinityCapacity);
            Edge* edgeForward = new Edge(projectVertex, areaVertex, this->infinityCapacity);
            Edge* edgeBackward = new Edge(areaVertex, projectVertex, 0);
            edgeForward->edgeRef = edgeG;
            edgeForward->isFordward = true;
            edgeBackward->edgeRef = edgeG;

            this->mapping.mapEdgeGToResidualG[edgeG] = pair<Edge*,Edge*>(edgeForward, edgeBackward);

            this->graph->addEdge(edgeG);
            this->residualGraph->addEdge(edgeForward);
            this->residualGraph->addEdge(edgeBackward);
        }
    }

}



