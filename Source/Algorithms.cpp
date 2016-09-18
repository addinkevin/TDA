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
	this->start_time = 0;
	this->stop_time = 0;
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
	//sample recording
	this->sample.insert(std::make_pair( std::make_pair(n,k),this->stop_time-this->start_time));
	return array[k];
}

map<pair<int,int>,int>* Algorithms::getSample(){
	return &this->sample;
}

int Algorithms::getExecutionTime(){
	return this->stop_time - this->start_time;
}

Algorithms::~Algorithms() {
	this->sample.erase(this->sample.begin(),this->sample.end());
}

} /* namespace std */
