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
	int array[] = {1,10,3,4,89,64,78};
	int length = sizeof(array)/sizeof(int);
	Utils::get()->quicksort(array,0,length);

	return 0;
}
