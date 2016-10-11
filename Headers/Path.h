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
	bool* marked;
	double* distance;
	Edge** edgeTo;
public:
	Path(Digraph* g, int source, int dest);
	virtual int getSource();
	virtual int getDest();
	virtual double distanceTo(int v);
	virtual bool visited(int v);
	virtual std::list<Edge*> pathTo(int v);
	virtual std::list<int> getVertexPath(int v);
	virtual ~Path();

	const double NO_PATH = std::numeric_limits<double>::max();
};

#endif /* PATH_H_ */
