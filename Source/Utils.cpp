/*
 * Utils.cpp
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#include "../Headers/Utils.h"

namespace std {

Utils* Utils::instance = NULL;

Utils::Utils() {

}

Utils* Utils::get(){
	if(!instance){
		instance = new Utils();
	}
	return instance;
}

// Función para dividir el array y hacer los intercambios
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

// Función recursiva para hacer el ordenamiento
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
