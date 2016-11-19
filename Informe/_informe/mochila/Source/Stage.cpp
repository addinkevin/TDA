#include <sstream>
#include "../Headers/Stage.h"


Stage::Stage() {
}

Stage::~Stage() {
}

void Stage::loadNode(string* line){
	Node newNode;

	stringstream ss;
	ss.str(*line);
	string item;
	getline(ss, item, ',');
	getline(ss, item, ',');
	newNode.valor = stoi(item);
	getline(ss, item, ',');
	newNode.weight = stoi(item);
	getline(ss, item, ',');
	newNode.isInBag = (bool)stoi(item);

	this->nodes.push_back(newNode);
}

bool Stage::isFull(){
	return (this->nodes.size() == this->qtyNode) && (this->qtyNode>=1);
}

Node Stage::getNode(int i){
	return this->nodes[i];
}

