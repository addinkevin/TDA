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
	
int  partition(vector<int>* array, int p,int r){
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

bool verificador(vector<int>* array,int candidate,int k){
    int leftCount = 0;
    for (int i = 0; i < array->size; i++) {
        if (array->at(i) < candidate) {
            leftCount++;
        }
    }
    return (leftCount == k);
}


    /* Busca la posicion del elemento mas chico, buscando a partir de initPosition */
int getPositionOfSmallerValue(vector<int>* array,int initPosition){
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
void changeSmallerWithInitial(vector<int>* array, int initPosition, int smallerPosition){
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

int Utils::quickSelect(vector<int>* array,int p, int r, int k){
    if ( p == r )
    	return array->at(p);
    int j = partition(array, p, r);
    int length = j - p + 1;

    if ( length == k )
    	return array->at(j);
    else if ( k < length )
    	return quickSelect(array, p, j - 1, k);
    else
    	return quickSelect(array, j + 1, r, k - length);
}

int Utils::bruteForce(vector<int>* array,int k){
	for(int i=0; i <= array->size(); i++){
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

} /* namespace std */
