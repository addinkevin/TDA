
#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Utils {
private:
	Utils();
	vector<int> array;
	static Utils* instance;

public:
	static Utils* get();
	vector<int> createArray(size_t n);
	vector<int> getArray();


	static int _quickSelect(vector<int>* array,int left, int right, int k);
    static int quickSelect(vector<int>* array,int k);
	static int bruteForce(vector<int>* array,int k);
	static int kSelection(vector<int>* array,int k);
    static int orderAndSelect(vector<int>* array, int k);
	static int kHeapSort(vector<int> *array, int k);
	static int heapSelect(vector<int> *array, int k);

	virtual ~Utils();


    static int partition(vector<int> *array, int left, int right);

    static bool verificador(vector<int> *array, int candidate, int k);

    static int getPositionOfSmallerValue(vector<int> *array, int initPosition);

    static void changeSmallerWithInitial(vector<int> *array, int initPosition, int smallerPosition);

    static void swap(vector<int>* array, int i, int j);
};

#endif /* UTILS_H_ */
