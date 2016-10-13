/*
 * Algorithms.cpp
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#include "../Headers/Algorithms.h"

using namespace std;

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

int Algorithms::quickSelect(vector<int>* array,int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->quickSelect(array, k);
	this->stop_time = clock();
	//sample recording
	this->quickSelectSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::orderAndSelect(vector<int>* array,int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->orderAndSelect(array, k);
	this->stop_time = clock();
	//sample recording
	this->orderAndSelectSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::bruteForce(vector<int>* array,int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->bruteForce(array,k);
	this->stop_time = clock();
	//sample recording
	this->bruteForceSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::kSelection(vector<int>* array,int k){
	this->start_time =  clock();
	int kMinValue = Utils::get()->kSelection(array,k);
	this->stop_time = clock();
	//sample recording
	this->kSelectSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
	return kMinValue;
}

int Algorithms::kHeapSort(vector<int> *array, int k) {
    this->start_time =  clock();
    int kMinValue = Utils::get()->kHeapSort(array,k);
    this->stop_time = clock();
    //sample recording
    this->kheapSortSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
    return kMinValue;
}

int Algorithms::heapSelect(vector<int> *array, int k) {
    this->start_time =  clock();
    int kMinValue = Utils::get()->heapSelect(array,k);
    this->stop_time = clock();
    //sample recording
    this->heapSelectSample.insert(std::make_pair( std::make_pair(array->size(),k),this->stop_time-this->start_time));
    return kMinValue;
}


int Algorithms::getExecutionTime(){
	return this->stop_time - this->start_time;
}

void Algorithms::_recordData(map<pair<int,int>, int> sampleMap, std::string fileName) {
    ofstream output;
    output.open(fileName);
    for(map<pair<int,int>, int>::iterator it = sampleMap.begin(); it !=sampleMap.end(); ++it){
        stringstream line;
        //n,k,time
        line << it->first.first <<"," << it->first.second <<","<<it->second<<'\n';
        output << line.str().c_str();
    }
    output.close();
}

void Algorithms::recordData(){
    _recordData(this->bruteForceSample, "bruteForce.csv");
    _recordData(this->orderAndSelectSample, "orderAndSelect.csv");
    _recordData(this->kSelectSample, "kSelect.csv");
    _recordData(this->kheapSortSample, "kHeapSort.csv");
    _recordData(this->heapSelectSample, "heapSelect.csv");
    _recordData(this->quickSelectSample, "quickSelect.csv");

}
Algorithms::~Algorithms() {
    this->bruteForceSample.erase(this->bruteForceSample.begin(),this->bruteForceSample.end());
	this->orderAndSelectSample.erase(this->orderAndSelectSample.begin(),this->orderAndSelectSample.end());
	this->kSelectSample.erase(this->kSelectSample.begin(),this->kSelectSample.end());
	this->kheapSortSample.erase(this->kheapSortSample.begin(),this->kheapSortSample.end());
	this->heapSelectSample.erase(this->heapSelectSample.begin(),this->heapSelectSample.end());
	this->quickSelectSample.erase(this->quickSelectSample.begin(),this->quickSelectSample.end());

}


