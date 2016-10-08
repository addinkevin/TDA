/*
 * Edge.h
 *
 *  Created on: Oct 1, 2016
 *      Author: gatti2602
 *
 *  Descripcion: Clase inmutable Edge, solo se asignan valores en la construccion,
 *  			 por lo que no se agregan setters
 */

#ifndef EDGE_H_
#define EDGE_H_

class Edge {
private:
	int source;
	int dest;
	double weight;
public:
	Edge(int source, int dest, double weight);
	int getSource();
	int getDest();
	double getWeight();


	~Edge();
};

#endif /* EDGE_H_ */
