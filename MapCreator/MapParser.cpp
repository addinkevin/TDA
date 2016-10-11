//
// Created by kevin on 10/10/16.
//

#include <sstream>
#include "MapParser.h"
#include "SVGDrawer.h"
#include "MapParserConstants.h"
#include <algorithm>

MapParser::MapParser(std::string fileName) {
    this->file = std::ifstream(fileName.c_str());
    this->digraph = NULL;
    this->parseFile();
}

MapParser::~MapParser() {
    this->file.close();
}

void MapParser::parseFile() {
    std::string line;

    while (std::getline(this->file,line)) {
        if (line.empty()) continue;
        std::istringstream stringStream(line);
        std::string field;
        getline(stringStream, field, ',');
        if (field == MapParserConstants::VISITED_STRING) {
            getline(stringStream, field);
            this->visitedColor = field;
        } else if (field == MapParserConstants::PATH_STRING) {
            getline(stringStream, field);
            this->pathColor = field;
        }
        else if (field == MapParserConstants::MAP_START_STRING) {
            processMapFromFile();
            return;
        } else {
            std::string element = field;
            getline(stringStream, field, ',');
            if (field == MapParserConstants::SOURCE_STRING) {
                this->sourceElement = element.at(0);
                getline(stringStream, field, ',');
                this->sourceColor = field;
                this->fileMap.insert(std::pair<char, PairCostColor>(element.at(0), PairCostColor(1,this->sourceColor)));
            } else if (field == MapParserConstants::DESTINATION_STRING) {
                this->destElement = element.at(0);
                getline(stringStream, field, ',');
                this->destColor = field;
                this->fileMap.insert(std::pair<char, PairCostColor>(element.at(0), PairCostColor(1,this->destColor)));
            } else {
                double cost = std::stod(field);
                getline(stringStream, field, ',');
                std::string color = field;

                std::cout << element.at(0) << "," << cost << "," << color << std::endl;

                this->fileMap.insert(std::pair<char, PairCostColor>(element.at(0), PairCostColor(cost,color)));
            }
        }
    }
}

bool MapParser::existVertexNum(int i, int j, int rows, int cols) {
    return ( i>= 0 && i < rows && j >= 0 && j < cols);
}

int  MapParser::calculateVertexNum(int i, int j, int rows, int cols) {
    if (!existVertexNum(i,j,rows,cols)) return -1;

    return j + i * cols;
}

void MapParser::_addEdge(int source, int dest, int cost) {
    if (cost == -1) return;
    this->digraph->addEdge(source,dest,cost);
}

void MapParser::createEdge(int actualRow, int actualCol, int otherRow, int otherCol, int rows, int cols) {
    int actualVertexNum = calculateVertexNum(actualRow, actualCol, rows, cols);
    double actualCost = this->graphMapCost[actualRow][actualCol];

    int otherVertexNum = calculateVertexNum(otherRow, otherCol, rows, cols);
    if (otherVertexNum == -1) return;

    double otherCost = this->graphMapCost[otherRow][otherCol];
    if (actualCost > 0) {
        _addEdge(otherVertexNum, actualVertexNum, actualCost);
    }

    if (otherCost > 0) {
        _addEdge(actualVertexNum, otherVertexNum, otherCost);
    }

}

void MapParser::_createGraph() {
    int rows = this->graphMapChar.size();
    int cols = this->graphMapChar.at(0).size();

    this->digraph = new Digraph(rows*cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int vertexNumber = calculateVertexNum(i,j,rows,cols);
            this->vertexMap.insert(std::pair<int,Vertex>(vertexNumber, Vertex(vertexNumber, i, j)));
            createEdge(i, j, i, j-1, rows, cols);
            createEdge(i, j, i, j+1, rows, cols);
            createEdge(i, j, i-1, j, rows, cols);
            createEdge(i, j, i+1, j, rows, cols);
        }
    }

}

Digraph *MapParser::createGraph() {
    if (this->digraph != NULL) {
        return this->digraph;
    }

    _createGraph();
    return this->digraph;
}

void MapParser::processMapFromFile() {
    std::string line;

    int row = 0;
    int vertexNum = 0;

    while (std::getline(this->file,line)) {
        if (line.empty()) continue;

        this->graphMapChar.push_back(std::vector<char>());
        this->graphMapCost.push_back(std::vector<double>());

        for (std::string::iterator it=line.begin(); it!=line.end(); ++it) {
            char element = *it;
            this->graphMapChar[row].push_back(element);
            this->graphMapCost[row].push_back(this->fileMap[element].first);

            if (element == this->sourceElement) {
                this->sourceVertexNum = vertexNum;
            } else if (element == this->destElement) {
                this->destVertexNum = vertexNum;
            }

            vertexNum++;
        }
        row++;
    }
}

void MapParser::drawGraph(std::string fileName) {
    int rows = this->graphMapChar.size();
    int cols = this->graphMapChar.at(0).size();

    int width = 50;
    int height = 50;

    SVGDrawer svgDrawer(fileName, cols * width, rows * height);

    int i = 0;
    int j = 0;

    for (std::vector<std::vector<char>>::iterator it = this->graphMapChar.begin(); it != this->graphMapChar.end(); ++it) {
        std::vector<char> vector = *it;
        j = 0;
        for (std::vector<char>::iterator it2 = vector.begin(); it2 != vector.end(); ++it2) {
            char element = *it2;
            std::string color = this->fileMap[element].second;
            svgDrawer.drawRectangle(j * width, i * height, width, height, color);
            j++;
        }
        i++;
    };
}

int MapParser::getDestVertex() {
    return this->destVertexNum;
}

int MapParser::getSourceVertex() {
    return this->sourceVertexNum;
}

void MapParser::drawGraphResults(std::string fileName, Path &pathAlgorithm) {
    int rows = this->graphMapChar.size();
    int cols = this->graphMapChar.at(0).size();

    int width = 50;
    int height = 50;

    std::list<int> vertexPath = pathAlgorithm.getVertexPath(this->destVertexNum);

    SVGDrawer svgDrawer(fileName, cols * width, rows * height);

    int i = 0;
    int j = 0;

    for (std::vector<std::vector<char>>::iterator it = this->graphMapChar.begin(); it != this->graphMapChar.end(); ++it) {
        std::vector<char> vector = *it;
        j = 0;
        for (std::vector<char>::iterator it2 = vector.begin(); it2 != vector.end(); ++it2) {
            char element = *it2;
            std::string color = this->fileMap[element].second;

            int vertexNum = calculateVertexNum(i, j, rows,cols);
            if (std::find(vertexPath.begin(), vertexPath.end(), vertexNum) != vertexPath.end()) {
                svgDrawer.drawRectangleWithMark(j * width, i * height, width, height, color, this->pathColor);
            } else if (pathAlgorithm.visited(vertexNum)) {
                svgDrawer.drawRectangleWithMark(j * width, i * height, width, height, color, this->visitedColor);
            } else {
                svgDrawer.drawRectangle(j * width, i * height, width, height, color);
            }

            j++;
        }
        i++;
    };
}

std::map<int, Vertex> MapParser::getVertexMap() {
    return this->vertexMap;
}

