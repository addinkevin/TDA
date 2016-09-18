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

namespace std {

class Utils {
private:
	Utils();
	static Utils* instance;
public:
	static Utils* get();
	int* createArray(size_t n);
	void quicksort(int* array,int start, int end);
	virtual ~Utils();
};

} /* namespace std */

#endif /* UTILS_H_ */
