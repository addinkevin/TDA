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
#include <iostream>
#include <fstream>
#include <sstream>

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

	int quickSelect(vector<int>* array,int left, int right, int k);
	int bruteForce(vector<int>* array,int k);
	int kSelection(vector<int>* array,int k);
    int orderAndSelect(vector<int>* array, int k);
	int kHeapSort(vector<int> *array, int k);
	int heapSelect(vector<int> *array, int k);

	virtual ~Utils();


    int partition(vector<int> *array, int p, int r);

    bool verificador(vector<int> *array, int candidate, int k);

    int getPositionOfSmallerValue(vector<int> *array, int initPosition);

    void changeSmallerWithInitial(vector<int> *array, int initPosition, int smallerPosition);
};

} /* namespace std */

#endif /* UTILS_H_ */
