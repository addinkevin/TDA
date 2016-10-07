/*
 * Path.h
 *
 *  Created on: Oct 4, 2016
 *      Author: gatti2602
 */

#ifndef PATH_H_
#define PATH_H_

#include "Digraph.h"
#include <list>
#include <limits>

class Path {
protected:
	Digraph* g;
	int source;
	int dest;
public:
	Path(Digraph* g, int source, int dest);
	virtual bool visited(int v)=0;
	virtual int distanceTo(int v)=0;
	virtual std::list<Edge*> pathTo(int v)=0;
	virtual ~Path();

	const int NO_PATH = std::numeric_limits<int>::max();
};

#endif /* PATH_H_ */
