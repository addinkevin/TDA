/*
 * Algorithms.h
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#include <time.h>
#include <map>
#include "Utils.h"

namespace std {

class Algorithms {
private:
	Algorithms();
	static Algorithms* instance;
	clock_t start_time;
	clock_t stop_time;
	map<pair<int,int>, int> kheapSortSample;		// [(n,k):excution_time]
	map<pair<int,int>, int> quickSelectSample;		// [(n,k):excution_time]
	map<pair<int,int>, int> heapSelectSample;		// [(n,k):excution_time]
	map<pair<int,int>, int> kSelectSample;		// [(n,k):excution_time]
	map<pair<int,int>, int> orderAndSelectSample;		// [(n,k):excution_time]
	map<pair<int,int>, int> bruteForceSample;		// [(n,k):excution_time]

	void _recordData(map<pair<int, int>, int> sampleMap, string fileName);

public:
	static Algorithms* get();
	int quickSelect(vector<int>* array,int left,int rigth,int k);
	int orderAndSelect(vector<int>* array,int k);
	int bruteForce(vector<int>* array,int k);
	int kSelection(vector<int>* array,int k);
	int kHeapSort(vector<int> *array, int k);
	int heapSelect(vector<int> *array, int k);

	int getExecutionTime();
	void recordData();
	virtual ~Algorithms();


};

} /* namespace std */

#endif /* ALGORITHMS_H_ */
