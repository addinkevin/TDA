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
public:
	PathBFS(Digraph* g, int source, int dest);
	virtual ~PathBFS();

};

#endif /* PATHBFS_H_ */
