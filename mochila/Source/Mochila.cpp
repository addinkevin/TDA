//============================================================================
// Name        : mochila.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Mochila.h"
#include <iostream>
#include <list>
#include <set>
#include <ctime>
#include "../Headers/Parser.h"
#include "../Headers/Stage.h"
#include "../Headers/Node.h"
using namespace std;

Mochila::Mochila(string ruta){
	initMochila(ruta);
}

int Mochila::initMochila(string ruta) {
	Parser* parser = new Parser();
	list<Stage>* lista = parser->getListOfStages(ruta);
	cout << "size lista " << (lista)->size()<< endl;
	cout <<"nombre,cantidad,peso,pesoFinal,tiempo"<<endl;
	for (list<Stage>::iterator it=lista->begin(); it != lista->end(); ++it){
		computarMochila(*it);
		(*it).print();
	}
	return 0;
}

void Mochila::computarMochila(Stage stage){

	unsigned t0, t1;
	t0=clock();
	int** tPesos = new int*[stage.qtyNode+1];
	for(int i = 0; i < stage.qtyNode+1; ++i)
	    tPesos[i] = new int[stage.capacityBag+1];

	//Se comenta  para mantener tiempos de calculo en NW y ahorro de memoria(1)
	//std::set<int> tSoluciones[stage.qtyNode+1][stage.capacityBag+1];
	//std::set<int> empty;

	for (int i=0;i<=stage.qtyNode;i++)
		for(int j=0;j<=stage.capacityBag;j++){
			tPesos[i][j] = 0;
			//(1)
			//	tSoluciones[i][j] = empty;
		}

	for(int i=1; i<=stage.qtyNode; i++){
		for(int w=0;w<=stage.capacityBag;w++){
			int weight = stage.getNode(i-1)->weight;
			int valor = stage.getNode(i-1)->valor;
			if(w < weight){
				tPesos[i][w] = tPesos[i-1][w];
				//(1)
				//	tSoluciones[i][w] = tSoluciones[i-1][w];
			}
			else{
				if(tPesos[i-1][w] > (valor + tPesos[i-1][w-weight])){
					tPesos[i][w] = tPesos[i-1][w];
					//(1)
					//	tSoluciones[i][w] = tSoluciones[i-1][w];
				}
				else{
					tPesos[i][w] = valor + tPesos[i-1][w-weight];
					//(1)
					//tSoluciones[i][w] = tSoluciones[i-1][w-weight];
					//tSoluciones[i][w].insert(i);
				}
			}
		}
	}
	//Imprimo objetos en la mochila
	/*
		std::set<int> mochilaFinal;
		mochilaFinal.swap(tSoluciones[stage.qtyNode][stage.capacityBag]);
		for ( std::set<int>::const_iterator si = mochilaFinal.begin( ) ;
			 si != mochilaFinal.end( ) ; si++ ) {
		      std::cout << *si << "\n" ;
		   }
	 */
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);

	//Imprimo resultados en csv
	cout<< stage.name<<","<<stage.qtyNode <<","<<stage.capacityBag<<","<<tPesos[stage.qtyNode][stage.capacityBag] << "," << time << endl;


	for(int i = 0; i < stage.qtyNode+1; ++i) {
	    delete [] tPesos[i];
	}
	delete [] tPesos;
}
Mochila::~Mochila(){

}

