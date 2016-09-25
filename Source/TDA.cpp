//============================================================================
// Name        : TDA.cpp
// Author      : Jorge
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Algorithms.h"
#include "../Headers/MathGl.h"

#include <iostream>

using namespace std;

//TODO el k minimo a veces no coincide. CHEQUEAR ALGORITMO!
int main() {
	int n = 950;
	int k = 75;
	int kMin;
	vector<int> array = Utils::get()->createArray(n);

	//QuickSort
	kMin = Algorithms::get()->quickSort(&array,n-1,k);
	cout << "[QuickSort] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[QuickSort] k elemento minimo: "<< kMin << endl;

	//Reset array
	array = Utils::get()->getArray();

	//HeapSort
	kMin = Algorithms::get()->heapSort(&array,n-1,k);
	cout << "[HeapSort] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[HeapSort] k elemento minimo: "<< kMin << endl;

	//Free memory
	Algorithms::get()->~Algorithms();
	Utils::get()->~Utils();
	return 0;
}
