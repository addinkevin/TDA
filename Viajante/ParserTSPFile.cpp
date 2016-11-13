//
// Created by kevin on 11/12/16.
//

#include <sstream>
#include "ParserTSPFile.h"

std::string ParserTSPFile::FULL_MATRIX = "FULL_MATRIX";

std::string ParserTSPFile::LOWER_DIAG_ROW = "LOWER_DIAG_ROW";

ParserTSPFile::ParserTSPFile(string matrixFileName, string solutionFileName) {
    this->matrixFile = ifstream(matrixFileName.c_str());
    if (!this->matrixFile.is_open()) {
        throw std::string("Error al abrir el archivo de la matriz: ") + matrixFileName;
    }
    this->solutionFile = ifstream(solutionFileName.c_str());
    if (!this->solutionFile.is_open()) {
        throw std::string("Error al abrir el archivo de la solucion: ") + solutionFileName;
    }
}

ParserTSPFile::~ParserTSPFile() {
    this->matrixFile.close();
    this->solutionFile.close();
}

vector<vector<CostInt>> *ParserTSPFile::getMatrix() {
    string line;
    getline(this->matrixFile, line);
    if (line == ParserTSPFile::FULL_MATRIX){
        return this->getFullMatrix();
    } else {
        return this->getLowerDiagRowMatrix();
    }
}

vector<CostInt> ParserTSPFile::splitLine(string line, char delim) {
    vector<CostInt > items;
    stringstream ss;
    ss.str(line);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            items.push_back(stoi(item));
        }
    }
    return items;
}

vector<vector<CostInt>> *ParserTSPFile::getFullMatrix() {
    vector<vector<CostInt >>* matrix = new vector<vector<CostInt >>();
    string line;
    while (getline(this->matrixFile, line)) {
        if (line.empty()) continue;
        vector<CostInt > row = this->splitLine(line, ' ');
        matrix->push_back(row);
    }

    return matrix;
}

vector<vector<CostInt >> *ParserTSPFile::getLowerDiagRowMatrix() {
    vector<vector<CostInt>>* matrix = new vector<vector<CostInt>>();
    matrix->push_back(vector<CostInt>());
    unsigned int actualRow = 0;
    unsigned int actualCol = 0;
    unsigned int rowLengthtoRead = 1;
    string line;
    while (getline(this->matrixFile, line)) {
        if (line.empty()) continue;
        unsigned int distance = stoi(line);
        matrix->at(actualRow).push_back(distance);
        if (actualRow != actualCol) {
            matrix->at(actualCol).push_back(distance);
        }
        actualCol += 1;
        if (actualCol >= rowLengthtoRead) {
            actualCol = 0;
            actualRow += 1;
            rowLengthtoRead += 1;
            matrix->push_back(vector<CostInt>());
        }
    }

    matrix->pop_back(); // Borrar la ultima lista vacia agregada.

    return matrix;

}

vector<VertexInt>* ParserTSPFile::getSolutionList() {
    vector<VertexInt>* lista = new vector<VertexInt>();
    string line;
    while (getline(this->solutionFile, line)) {
        if (line.empty()) continue;
        VertexInt vertex = stoi(line) - 1;
        lista->push_back(vertex);
    }

    return lista;
}
