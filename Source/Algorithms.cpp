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

int Algorithms::quickSort(vector<int>* array,int n,int k){
	this->start_time = clock();
	Utils::get()->quicksort(array,0,n);
	this->stop_time = clock();
	//sample recording
	this->qsSample.insert(std::make_pair( std::make_pair(n,k),this->stop_time-this->start_time));
	return  array->at(k);
}

int Algorithms::heapSort(vector<int>* array,int n,int k){
	this->start_time =  clock();
	Utils::get()->heapsort(array,n);
	this->stop_time = clock();
	//sample recording
	this->hsSample.insert(std::make_pair( std::make_pair(n,k),this->stop_time-this->start_time));
	return array->at(k);
}
	
int Algorithms::quickSelect(vector<int>* array,int left, int right, int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->quickSelect(array,left,right,k);
	this->stop_time = clock();
	return kMinValue;
}

int Algorithms::nativeSort(vector<int>* array,int k){
	this->start_time =  clock();
	std::sort(array->begin(),array->end());
	this->stop_time = clock();
	return array->at(k);
}
	
map<pair<int,int>,int>* Algorithms::getSample(){
	return &this->qsSample;
}

int Algorithms::getExecutionTime(){
	return this->stop_time - this->start_time;
}

Algorithms::~Algorithms() {
	this->qsSample.erase(this->qsSample.begin(),this->qsSample.end());
	this->hsSample.erase(this->hsSample.begin(),this->hsSample.end());
}

} /* namespace std */
