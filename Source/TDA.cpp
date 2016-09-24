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

int main() {
	int n = 1002500;
	int k = 6;
	int kMin;
	int* array = Utils::get()->createArray(n);

	//QuickSort
	kMin = Algorithms::get()->quickSort(array,n,k);
	cout << "[QuickSort] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[QuickSort] k elemento minimo: "<< kMin << endl;

	//HeapSort
	kMin = Algorithms::get()->heapSort(array,n,k);
	cout << "[HeapSort] Tiempo de ejecucion: "<< Algorithms::get()->getExecutionTime()<<endl;
	cout << "[HeapSort] k elemento minimo: "<< kMin << endl;

	//Free memory
	Algorithms::get()->~Algorithms();
	Utils::get()->~Utils();
	delete[] array;
	return 0;
}
