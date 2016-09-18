//============================================================================
// Name        : TDA.cpp
// Author      : Jorge
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Utils.h"

#include <iostream>

using namespace std;

int main() {
	int n = 5;
	int* array = Utils::get()->createArray(n);


	Utils::get()->quicksort(array,0,n-1);
	for(int i = 0; i < n; i++){
		cout << array[i] << endl;
	}
	return 0;
}
