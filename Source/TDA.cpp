//============================================================================
// Name        : TDA.cpp
// Author      : Jorge
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Algorithms.h"
#include "../Headers/Digraph.h"

#include <iostream>

using namespace std;

//Ejecuta funciones de Grafos (libera el main de tanto codigo)
void runGraphs(){
	cout << endl;
	cout << "[Algoritmos de Grafos]" << endl;
	Digraph* g = new Digraph(10);
	g->addEdge(1,2,3);
	cout << endl;
}

int main() {
	int n = 1500;
	int k = 0;
	int kMin;

	//create differents arrays with the same k value
	for(int i=1; i <= 100; i++){
		n = 150 * i;
		vector<int> array = Utils::get()->createArray(n);

		//QuickSort
		kMin = Algorithms::get()->quickSort(&array,n-1,k);

		//Native c++ sort
		array = Utils::get()->getArray();
		kMin = Algorithms::get()->nativeSort(&array,k);

		//QuickSelect
		array = Utils::get()->getArray();
		kMin = Algorithms::get()->quickSelect(&array,0,n-1,k);

		//BruteForce
		array = Utils::get()->getArray();
		kMin = Algorithms::get()->bruteForce(&array,k);

		//KSelection
		array = Utils::get()->getArray();
		kMin = Algorithms::get()->kSelection(&array,k);
	}

	//Save data into .csv file
	Algorithms::get()->recordData();

	//Free memory
	Algorithms::get()->~Algorithms();
	Utils::get()->~Utils();

	//runGraphs();
	return 0;
}


