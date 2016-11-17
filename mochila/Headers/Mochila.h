/*
 * mochila.h
 *
 *  Created on: 14 de nov. de 2016
 *      Author: gatti2602
 */

#ifndef MOCHILA_H_
#define MOCHILA_H_
#include "../Headers/Parser.h"
#include "../Headers/Stage.h"
#include "../Headers/Node.h"
using namespace std;

class Mochila {

public:
	Mochila();
	~Mochila();

private:
	int initMochila();
	void computarMochila(Stage);
};

#endif /* MOCHILA_H_ */
