/*
 * Parser.h
 *
 *  Created on: 12 de nov. de 2016
 *      Author: jorlando
 */

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

	list<Stage> getListOfStages(string path);
	~Parser();
};





#endif /* PARSER_H_ */
