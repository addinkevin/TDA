/*
 * Utils.cpp
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#include "../Headers/Utils.h"

using namespace std;

Utils* Utils::instance = NULL;

/*
 * AUXILIAR FUNCTIONS
 * */

/*
int Utils::partition(vector<int>* array, int p,int r){
    int pivot = array->at(r);

    while ( p < r )
    {
        while ( array->at(p) < pivot )
            p++;

        while ( array->at(r) > pivot )
            r--;

        if ( array->at(p) == array->at(r) )
            p++;
        else if ( p < r ) {
            int tmp = array->at(p);
            array->at(p) = array->at(r);
            array->at(r) = tmp;
        }
    }

    return r;
}
*/

void Utils::swap(vector<int>* array, int i, int j) {
    int tmp = array->at(i);
    array->at(i) = array->at(j);
    array->at(j) = tmp;
}

int Utils::partition(vector<int>* array, int left, int right) {
    int pivotIndex = left + std::rand() % (right - left);
    int pivotValue = array->at(pivotIndex);

    swap(array,pivotIndex, right); // Move pivot to end
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if(array->at(i) < pivotValue) {
            swap(array, storeIndex, i);
            storeIndex++;
        }
    }
    swap(array, right, storeIndex); // Move pivot to its final place
    return storeIndex;
}
bool Utils::verificador(vector<int>* array,int candidate,int k){
    int leftCount = 0;
    for (int i = 0; i < array->size(); i++) {
        if (array->at(i) < candidate) {
            leftCount++;
        }
    }
    return (leftCount == k);
}


    /* Busca la posicion del elemento mas chico, buscando a partir de initPosition */
int Utils::getPositionOfSmallerValue(vector<int>* array,int initPosition){
	int smallerPosition = initPosition;
	int smallerValue = array->at(initPosition);
	for(int auxPosition = (initPosition+1); auxPosition < array->size(); auxPosition++){
		if(array->at(auxPosition) < smallerValue){
			smallerPosition = auxPosition;
			smallerValue = array->at(auxPosition);
		}
	}
	return smallerPosition;
}

    /* Swap entre initPosition y smallerPosition */
void Utils::changeSmallerWithInitial(vector<int>* array, int initPosition, int smallerPosition){
	int initValue = array->at(initPosition);
	int smallerValue = array->at(smallerPosition);

    array->at(initPosition) = smallerValue;
    array->at(smallerPosition) = initValue;
}

void printArray(vector<int>* array){
	cout << " VECTOR: ";
	for(int indexArray=0; indexArray<array->size(); indexArray++){
			cout << array->at(indexArray) << " ; ";
	}
	cout << " "<< endl;
}


/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * */

Utils::Utils() {

}

Utils* Utils::get(){
	if(!instance){
		instance = new Utils();
	}
	return instance;
}

int Utils::_quickSelect(vector<int>* array,int left, int right, int k){
    if ( left == right )
    	return array->at(left);

    int pivotIndex = partition(array, left, right);

    if ( pivotIndex == k )
    	return array->at(pivotIndex);
    else if ( k < pivotIndex )
    	return _quickSelect(array, left, pivotIndex - 1, k);
    else
    	return _quickSelect(array, pivotIndex + 1, right, k);
}
int Utils::quickSelect(vector<int>* array, int k) {
    return _quickSelect(array, 0, array->size()-1, k);
}

int Utils::bruteForce(vector<int>* array,int k){
	for(int i=0; i < array->size(); i++){
		if(verificador(array,array->at(i),k))
			return array->at(i);
	}
	return -1;
}

int Utils::kSelection(vector<int>* array,int k){
	for(int indexArray=0; (indexArray<array->size() && indexArray <= k); indexArray++){
		int position = getPositionOfSmallerValue(array, indexArray);
		changeSmallerWithInitial(array, indexArray, position);
	}
	return array->at(k);
}

int Utils::orderAndSelect(vector<int> *array, int k) {
    std::sort(array->begin(),array->end());
    return array->at(k);
}

int Utils::kHeapSort(vector<int>* array, int k) {
    std::make_heap(array->begin(), array->end(), std::greater<int>()); // Heapify

    int extraccion;
    // K extracciones
    for (int i = 0; i < k + 1 ; i++) {
        std::pop_heap(array->begin(), array->end(), std::greater<int>());
        extraccion = array->back();
        array->pop_back();
    }

    return extraccion;
}

int Utils::heapSelect(vector<int>* array, int k) {
    std::vector<int> heapK(array->begin(), array->begin()+k+1);
    std::make_heap(heapK.begin(), heapK.end()); // Heapify de los k primeros elementos.

    for (int i = k+1 ; i < array->size(); i++) {
        if (heapK.at(0) > array->at(i)) {
            std::pop_heap(heapK.begin(), heapK.end());
            heapK.pop_back();
            heapK.push_back(array->at(i));
            std::push_heap(heapK.begin(), heapK.end());
        }
    }

    return heapK.at(0);
}

vector<int> Utils::createArray(size_t n){
	//At first clear data from array
	this->array.clear();
	//Allocate memory for n items, but array is still empty
	this->array.reserve(n);
	int max = 100;
	for(size_t i = 0; i < n; i++){
		this->array.push_back(rand()%max);
	}
	return this->array;
}

vector<int> Utils::getArray(){
	return this->array;
}

Utils::~Utils() {

}