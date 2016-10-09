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
	this->qsSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
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
	//sample recording
	this->qSSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::nativeSort(vector<int>* array,int k){
	this->start_time =  clock();
	std::sort(array->begin(),array->end());
	this->stop_time = clock();
	//sample recording
	this->nsSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return array->at(k);
}

int Algorithms::bruteForce(vector<int>* array,int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->bruteForce(array,k);
	this->stop_time = clock();
	//sample recording
	this->bfSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::kSelection(vector<int>* array,int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->kSelection(array,k);
	this->stop_time = clock();
	//sample recording
	this->ksSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::getExecutionTime(){
	return this->stop_time - this->start_time;
}

void Algorithms::recordData(){
	//quickSort data
	ofstream qsSample;
	qsSample.open("quickSort.csv");
	for(map<pair<int,int>, int>::iterator it = this->qsSample.begin(); it !=this->qsSample.end(); ++it){
		stringstream line;
		line << "n:" << it->first.first <<",k:" << it->first.second <<",time:"<<it->second<<'\n';
		qsSample << line.str().c_str();
	}
	qsSample.close();

	//quickSelect
	ofstream qSSample;
	qSSample.open("quickSelect.csv");
	for(map<pair<int,int>, int>::iterator it = this->qSSample.begin(); it !=this->qSSample.end(); ++it){
		stringstream line;
		line << "n:" << it->first.first <<",k:" << it->first.second <<",time:"<<it->second<<'\n';
		qSSample << line.str().c_str();
	}
	qSSample.close();

	//nativeSort
	ofstream nsSample;
	nsSample.open("nativeSort.csv");
	for(map<pair<int,int>, int>::iterator it = this->nsSample.begin(); it !=this->nsSample.end(); ++it){
		stringstream line;
		line << "n:" << it->first.first <<",k:" << it->first.second <<",time:"<<it->second<<'\n';
		nsSample << line.str().c_str();
	}
	nsSample.close();

	//bruteForce
	ofstream bfSample;
	bfSample.open("bruteForce.csv");
	for(map<pair<int,int>, int>::iterator it = this->bfSample.begin(); it !=this->bfSample.end(); ++it){
		stringstream line;
		line << "n:" << it->first.first <<",k:" << it->first.second <<",time:"<<it->second<<'\n';
		bfSample << line.str().c_str();
	}
	bfSample.close();

	//kSelection
	ofstream ksSample;
	ksSample.open("kSelection.csv");
	for(map<pair<int,int>, int>::iterator it = this->ksSample.begin(); it !=this->ksSample.end(); ++it){
		stringstream line;
		line << "n:" << it->first.first <<",k:" << it->first.second <<",time:"<<it->second<<'\n';
		ksSample << line.str().c_str();
	}
	ksSample.close();
}
Algorithms::~Algorithms() {
	this->qsSample.erase(this->qsSample.begin(),this->qsSample.end());
	this->hsSample.erase(this->hsSample.begin(),this->hsSample.end());
	this->qSSample.erase(this->hsSample.begin(),this->hsSample.end());
	this->nsSample.erase(this->hsSample.begin(),this->hsSample.end());
	this->bfSample.erase(this->hsSample.begin(),this->hsSample.end());
	this->ksSample.erase(this->hsSample.begin(),this->hsSample.end());
}

} /* namespace std */
