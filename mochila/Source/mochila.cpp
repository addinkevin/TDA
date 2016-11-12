//============================================================================
// Name        : mochila.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../Headers/Parser.h"
#include <list>
using namespace std;

int main() {
	Parser* parser = new Parser();
	list<Stage>* lista = parser->getListOfStages("/home/jorlando/test.csv");

	for (list<Stage>::iterator it=lista->begin(); it != lista->end(); ++it){
		cout << "ES EL STAGE" <<  it->name << endl;
		(*it).print();
	}
	return 0;
}
