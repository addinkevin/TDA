/*
 * Stage.h
 *
 *  Created on: 12 de nov. de 2016
 *      Author: jorlando
 */

#ifndef STAGE_H_
#define STAGE_H_

#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* atoi */
#include "../Headers/Node.h"

using namespace std;

class Stage {

public:
	string name;
	int qtyNode;
	int capacityBag;
	list<Node*> nodes = *(new list<Node*>());

	void loadNode(string* line);
	bool isFull();
	void print();

	Stage();
	~Stage();
};


#endif /* STAGE_H_ */
