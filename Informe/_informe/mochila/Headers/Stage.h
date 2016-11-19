#ifndef STAGE_H_
#define STAGE_H_

#include <vector>
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
    int optimo;

	vector<Node> nodes;

	void loadNode(string* line);
	bool isFull();
	Node getNode(int);

	Stage();
	~Stage();
};


#endif /* STAGE_H_ */
