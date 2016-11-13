//
// Created by kevin on 11/12/16.
//

#ifndef TRABAJOPRACTICO2_PARSERTSPFILE_H
#define TRABAJOPRACTICO2_PARSERTSPFILE_H

#include "Types.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class ParserTSPFile {
private:
    static string FULL_MATRIX;
    static string LOWER_DIAG_ROW;

    ifstream matrixFile;
    ifstream solutionFile;

    vector<vector<CostInt>>* getFullMatrix();
    vector<vector<CostInt>>* getLowerDiagRowMatrix();

    vector<CostInt> splitLine(string line, char delim);

public:
    ParserTSPFile(string matrixFileName, string solutionFileName);
    ~ParserTSPFile();

    vector<vector<CostInt>>* getMatrix();
    vector<VertexInt>* getSolutionList();



};


#endif //TRABAJOPRACTICO2_PARSERTSPFILE_H
