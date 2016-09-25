/*
 * Utils.cpp
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#include "../Headers/Utils.h"

namespace std {

Utils* Utils::instance = NULL;

/*
 * AUXILIAR FUNCTIONS
 * */
void max_heapify(vector<int>* a, int i, int n){
    int j, temp;
    temp = a->at(i);
    j = 2*i;
    while (j <= n){
        if (j < n && a->at(j+1) > a->at(j))
            j = j+1;
        if (temp > a->at(j)){
            break;
        }else if (temp <= a->at(j)){
            a->at(j/2) = a->at(j);
            j = 2*j;
        }
    }
    a->at(j/2) = temp;
    return;
}

void build_maxheap(vector<int>* a, int n){
    int i;
    for(i = n/2; i >= 1; i--){
        max_heapify(a, i, n);
    }
}

//QS: Función para dividir el array y hacer los intercambios
int  divide(vector<int>* array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array->at(start);
    left = start;
    right = end;
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array->at(right) > pivot) {
            right--;
        }
        while ((left < right) && (array->at(left) <= pivot)) {
            left++;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array->at(left);
            array->at(left) = array->at(right);
            array->at(right) = temp;
        }
    }
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array->at(right);
    array->at(right) = array->at(start);
    array->at(start) = temp;
    // La nueva posición del pivot
    return right;
}

Utils::Utils() {

}

Utils* Utils::get(){
	if(!instance){
		instance = new Utils();
	}
	return instance;
}



void  Utils::quicksort(vector<int>* array, int start, int end){
    int pivot;
    if (start < end) {
        pivot = divide(array, start, end);
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

void Utils::heapsort(vector<int>* a, int n){
    build_maxheap(a,n);
	int i, temp;
    for (i = n; i >= 2; i--){
        temp = a->at(i);
        a->at(i) = a->at(1);
        a->at(1) = temp;
        max_heapify(a, 1, i - 1);
    }
}

vector<int> Utils::createArray(size_t n){
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

} /* namespace std */
