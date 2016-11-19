#ifndef PARSER_H_
#define PARSER_H_

#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* atoi */
#include "../Headers/Stage.h"

using namespace std;

class Parser {

public:
	Parser();
	vector<Stage>* getListOfStages(string path);
	~Parser();
};





#endif /* PARSER_H_ */
