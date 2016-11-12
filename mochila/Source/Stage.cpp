/*
 * Stage.cpp
 *
 *  Created on: 12 de nov. de 2016
 *      Author: jorlando
 */

#include "../Headers/Stage.h"


Stage::Stage() {
}

Stage::~Stage() {
	// TODO Auto-generated destructor stub
}

void Stage::loadNode(string* line){
	//cout << "ENTRE AL LOAD NODE se STAGE " << *line<<endl;
	Node* newNode = new Node();

	string lineWithoutNumberNode = line->substr(line->find(",")+1);

	size_t posEndValor = lineWithoutNumberNode.find(",");
	string valorStr = lineWithoutNumberNode.substr(0,posEndValor);
	newNode->valor = atoi(valorStr.c_str());

	string lineWithoutValor = lineWithoutNumberNode.substr(posEndValor+1);
	size_t posEndWeight = lineWithoutValor.find(",");

	string weightStr = lineWithoutValor.substr(0,posEndWeight);
	newNode->weight = atoi(weightStr.c_str());
	this->nodes.push_back(newNode);
}

void Stage::print(){
	for (list<Node*>::iterator it=this->nodes.begin(); it != this->nodes.end(); ++it){
			cout << "Nodo valor: " <<  (*it)->valor << " peso: "<< (*it)->weight<<  endl;
		}
}
bool Stage::isFull(){
	//cout << "this->nodes.size() " << this->nodes.size() << " this->qtyNode " << this->qtyNode << endl;
	return (this->nodes.size() == this->qtyNode) && (this->qtyNode>=1);
}

