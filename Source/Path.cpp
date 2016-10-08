/*
 * Path.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: gatti2602
 */

#include "../Headers/Path.h"

	Path::Path(Digraph* g, int source, int dest){
		this->g = g;
		this->source = source;
		this->dest = dest;

	}

Path::~Path() {
	// TODO Auto-generated destructor stub
}

