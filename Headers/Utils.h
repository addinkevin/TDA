/*
 * Utils.h
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

namespace std {

class Utils {
private:
	Utils();
	vector<int> array;
	static Utils* instance;
public:
	static Utils* get();
	vector<int> createArray(size_t n);
	vector<int> getArray();
	void quicksort(vector<int>* array,int start, int end);
	void heapsort(vector<int>* array,int n);
	int quickSelect(vector<int>* array,int left, int right, int k);
	int bruteForce(vector<int>* array,int k);
	virtual ~Utils();
};

} /* namespace std */

#endif /* UTILS_H_ */
