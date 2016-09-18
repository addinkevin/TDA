/*
 * Algorithms.cpp
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#include "../Headers/Algorithms.h"

namespace std {

Algorithms* Algorithms::instance = NULL;

Algorithms::Algorithms() {
	// TODO Auto-generated constructor stub

}

Algorithms* Algorithms::get(){
	if(!instance){
		instance = new Algorithms();
	}
	return instance;
}

int Algorithms::quickSorting(int* array,int n,int k){
	this->start_time = clock();
	Utils::get()->quicksort(array,0,n-1);
	this->stop_time = clock();
	return array[k];
}

int Algorithms::getExecutionTime(){
	return this->stop_time - this->start_time;
}

Algorithms::~Algorithms() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
