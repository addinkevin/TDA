/*
 * PathBFS.h
 *
 *  Created on: Oct 4, 2016
 *      Author: gatti2602
 */

#ifndef PATHBFS_H_
#define PATHBFS_H_

#include "Path.h"

class PathBFS: public Path {

private:
	bool* marked;
	int* distance;
	Edge** edgeTo;

public:
	PathBFS(Digraph* g, int source, int dest);
	virtual ~PathBFS();

	bool visited(int v);
	int distanceTo(int v);
	std::list<Edge*> pathTo(int v);
};

#endif /* PATHBFS_H_ */
