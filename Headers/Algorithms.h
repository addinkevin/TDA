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
	map<pair<int,int>, int> qsSample;		// [(n,k):excution_time]
	map<pair<int,int>, int> hsSample;		// [(n,k):excution_time]
	clock_t start_time;
	clock_t stop_time;
public:
	static Algorithms* get();
	int quickSort(vector<int>* array,int n,int k);
	int heapSort(vector<int>* array,int n,int k);
	int quickSelect(vector<int>* array,int left,int rigth,int k);
	int getExecutionTime();
	map<pair<int,int>,int>* getSample();
	virtual ~Algorithms();
};

} /* namespace std */

#endif /* ALGORITHMS_H_ */
