//============================================================================
// Name        : TDA.cpp
// Author      : Jorge
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Algorithms.h"
#include "../Headers/MathGl.h"
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
	int n = 1025465;
	int k = 98;
	int kMin;
	vector<int> array = Utils::get()->createArray(n);

	//QuickSort
	kMin = Algorithms::get()->quickSort(&array,n-1,k);
	cout << "[QuickSort] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[QuickSort] k elemento minimo: "<< kMin << endl;

	//Native c++ sort
	array = Utils::get()->getArray();
	kMin = Algorithms::get()->nativeSort(&array,k);
	cout << "[NativeSort] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[NativeSort] k elemento minimo: "<< kMin << endl;

	//QuickSelect
	array = Utils::get()->getArray();
	kMin = Algorithms::get()->quickSelect(&array,0,n-1,++k);
	cout << "[QuickSelect] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[QuickSelect] k elemento minimo: "<< kMin << endl;

	//Free memory
	Algorithms::get()->~Algorithms();
	Utils::get()->~Utils();

	//runGraphs();
	return 0;
}


