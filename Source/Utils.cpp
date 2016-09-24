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
void max_heapify(int *a, int i, int n){
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n){
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j]){
            break;
        }else if (temp <= a[j]){
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void build_maxheap(int *a, int n){
    int i;
    for(i = n/2; i >= 1; i--){
        max_heapify(a, i, n);
    }
}

//QS: Función para dividir el array y hacer los intercambios
int  divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
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



void  Utils::quicksort(int *array, int start, int end){
    int pivot;
    if (start < end) {
        pivot = divide(array, start, end);
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

void Utils::heapsort(int *a, int n){
    build_maxheap(a,n);
	int i, temp;
    for (i = n; i >= 2; i--){
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}

int* Utils::createArray(size_t n){
	int* array = new int[n];
	for(size_t i = 0; i < n; i++){
		array[i] = rand();
	}
	return array;
}

Utils::~Utils() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
