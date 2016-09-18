//============================================================================
// Name        : TDA.cpp
// Author      : Jorge
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Utils.h"
#include "../Headers/Algorithms.h"

#include <iostream>

using namespace std;

int main() {
	int n = 10000;
	int k = 6;
	int* array = Utils::get()->createArray(n);
	Algorithms::get()->quickSorting(array,n,k);
	cout << Algorithms::get()->getExecutionTime()<<endl;
	return 0;
}
