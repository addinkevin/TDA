/*
 * Algorithms.h
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#include <time.h>
#include "Utils.h"

namespace std {

class Algorithms {
private:
	Algorithms();
	static Algorithms* instance;
	clock_t start_time;
	clock_t stop_time;
public:
	static Algorithms* get();
	int quickSorting(int* array,int n,int k);
	int getExecutionTime();
	virtual ~Algorithms();
};

} /* namespace std */

#endif /* ALGORITHMS_H_ */
