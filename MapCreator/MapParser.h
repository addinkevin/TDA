//
// Created by kevin on 10/10/16.
//

#ifndef TDA_MAPPARSER_H
#define TDA_MAPPARSER_H

#include "../Headers/Digraph.h"
#include "../Headers/Path.h"
#include "../Headers/Vertex.h"
#include <string>
#include <fstream>
#include <map>

typedef std::pair<double,std::string> PairCostColor;


class MapParser {
private:
    std::ifstream file;
    Digraph* digraph;
    int sourceVertexNum;
    int destVertexNum;

    char sourceElement;
    std::string sourceColor;
    char destElement;
    std::string destColor;
    std::string visitedColor;
    std::string pathColor;

    std::map<int,Vertex> vertexMap;
    std::map<char, PairCostColor> fileMap;
    std::vector<std::vector<char>> graphMapChar;
    std::vector<std::vector<double>> graphMapCost;

    void _createGraph();
    void parseFile();
    void processMapFromFile();
    int calculateVertexNum(int i, int j, int rows, int cols);
    bool existVertexNum(int i, int j, int rows, int cols);
    void _addEdge(int source, int dest, int cost);
    void createEdge(int actualRow, int actualCol, int otherRow, int otherCol, int rows, int cols);
public:
    MapParser(std::string fileName);
    ~MapParser();
    Digraph* createGraph();

    void drawGraph(std::string fileName);
    void drawGraphResults(std::string fileName, Path& pathAlgorithm);

    int getSourceVertex();
    int getDestVertex();

    std::map<int,Vertex> getVertexMap();
};


#endif //TDA_MAPPARSER_H
