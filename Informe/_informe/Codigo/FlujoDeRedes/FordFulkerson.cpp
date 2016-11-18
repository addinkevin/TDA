#include "FordFulkerson.h"
#include "ParserNetworkFlow.h"
#include "PathBFS.h"

FordFulkerson::FordFulkerson(ParserNetworkFlow* parser) {
    this->parser = parser;
    this->flow = new Flow(parser->graph);

}

FordFulkerson::~FordFulkerson() {
    delete flow;
}

/*
 * Calcula el cuello de botella del camino pasado como argumento
 */
int FordFulkerson::bottleneck(vector<Edge *> pathInResidualGraph) {
    int min = pathInResidualGraph.at(0)->getCapacity();

    for (unsigned int i = 1; i < pathInResidualGraph.size(); i++) {
        int residualCapacity = pathInResidualGraph.at(i)->getCapacity();
        if (residualCapacity < min) {
            min = residualCapacity;
        }
    }
    return min;
}


Edge *FordFulkerson::getEdgeInG(Edge *edgeInGResidual) {
    return this->parser->mapping.mapEdgeResidualGToEdgeG[edgeInGResidual];
}


bool FordFulkerson::isEdgeForward(Edge* edgeInGResidual) {
    return this->parser->mapping.isEdgeResidualForward[edgeInGResidual];
}

void FordFulkerson::augment(vector<Edge *> pathInResidualGraph) {
    int b = this->bottleneck(pathInResidualGraph);
    for (vector<Edge*>::iterator it = pathInResidualGraph.begin(); it != pathInResidualGraph.end(); ++it) {
        Edge* edgeInGResidual = *it;
        Edge* edgeInG = this->getEdgeInG(edgeInGResidual);
        int newFlow;
        if (this->isEdgeForward(edgeInGResidual)) {
            newFlow = this->flow->getEdgeInfo(edgeInG)->getFlow() + b;
        } else {
            newFlow = this->flow->getEdgeInfo(edgeInG)->getFlow() - b;
        }

        this->flow->getEdgeInfo(edgeInG)->setFlow(newFlow);
        pair<Edge*,Edge*> edgesInResidualG = this->parser->mapping.mapEdgeGToResidualG[edgeInG];
        Edge* edgeForward = edgesInResidualG.first;
        Edge* edgeBackward = edgesInResidualG.second;
        edgeForward->setCapacity(edgeInG->getCapacity() - newFlow);
        edgeBackward->setCapacity(newFlow);
    }
}

vector<Edge *> FordFulkerson::getPathST() {
    int sVertex = 0;
    int tVertex = this->parser->areasCount + this->parser->projectsCount + 1;
    vector<Edge*> path;
    PathBFS pathBFS(this->parser->residualGraph, sVertex, tVertex);
    if (pathBFS.visited(tVertex)) {
        std::list<Edge*> pathList = pathBFS.pathTo(tVertex);
        for (std::list<Edge*>::iterator it = pathList.begin(); it != pathList.end(); ++it) {
            Edge*edge = *it;
            path.push_back(edge);
        }
    }

    return path;
}

void FordFulkerson::maxFlow() {
    while (true) {
        vector<Edge*> path = getPathST();
        if (path.empty()) break;
        this->augment(path);
    }

    this->calculateMinCut();
}

void FordFulkerson::calculateMinCut() {
    int sVertex = 0;
    int tVertex = this->parser->areasCount + this->parser->projectsCount + 1;

    PathBFS pathBFS(this->parser->residualGraph, sVertex, tVertex);
    for (int i = 1; i < this->parser->residualGraph->getVertices() - 1; i++) {
        if (pathBFS.visited(i)) {
            this->setS.push_back(i);
        } else {
            this->setT.push_back(i);
        }
    }
}

vector<int> FordFulkerson::getSetT() {
    return this->setT;
}

vector<int> FordFulkerson::getSetS() {
    return this->setS;
}

vector<int> FordFulkerson::getProjects() {
    vector<int> projectsToDo;
    for (std::vector<int>::iterator it = this->setS.begin(); it != this->setS.end(); ++it ) {
        VertexInfo vertexInfo = this->parser->vertexMap[(*it)];
        if (vertexInfo.isProject) {
            projectsToDo.push_back(vertexInfo.number);
        }
    }
    return projectsToDo;
}

vector<int> FordFulkerson::getAreas() {
    vector<int> areasToPay;
    for (std::vector<int>::iterator it = this->setS.begin(); it != this->setS.end(); ++it ) {
        VertexInfo vertexInfo = this->parser->vertexMap[(*it)];
        if (!vertexInfo.isProject) {
            areasToPay.push_back(vertexInfo.number);
        }
    }
    return areasToPay;
}
