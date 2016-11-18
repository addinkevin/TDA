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
#include "../Headers/Parser.h"
#include "../Headers/Stage.h"
#include "../Headers/Node.h"
using namespace std;

Mochila::Mochila(){
	initMochila();
}

int Mochila::initMochila() {
	Parser* parser = new Parser();
	string ruta = "/home/gatti2602/Downloads/smallcoeff_pisinger/knapPI_1_50_1000.csv";
	list<Stage>* lista = parser->getListOfStages(ruta);
	cout << "size lista " << (lista)->size()<< endl;
	for (list<Stage>::iterator it=lista->begin(); it != lista->end(); ++it){
		cout << "ES EL STAGE" <<  it->name << endl;
		computarMochila(*it);
		(*it).print();
	}
	return 0;
}

void Mochila::computarMochila(Stage stage){
	//cout << "ComputarMochila: start" << endl;
	int tPesos[stage.qtyNode+1][stage.capacityBag+1];
	std::set<int> tSoluciones[stage.qtyNode+1][stage.capacityBag+1];
	std::set<int> empty;
	try{

		for (int i=0;i<stage.qtyNode;i++)
			for(int j=0;j<=stage.capacityBag;j++){
				tPesos[i][j] = 0;
				tSoluciones[i][j] = empty;

			}

		for(int i=1; i<=stage.qtyNode; i++){
			for(int w=0;w<=stage.capacityBag;w++){
				int weight = stage.getNode(i-1)->weight;
				int valor = stage.getNode(i-1)->valor;
				if(w < weight){
					tPesos[i][w] = tPesos[i-1][w];
					tSoluciones[i][w] = tSoluciones[i-1][w];
				}
				else{
					if(tPesos[i-1][w] > (valor + tPesos[i-1][w-weight])){
						tPesos[i][w] = tPesos[i-1][w];
						tSoluciones[i][w] = tSoluciones[i-1][w];
					}
					else{
						tPesos[i][w] = valor + tPesos[i-1][w-weight];
						tSoluciones[i][w] = tSoluciones[i-1][w-weight];
						tSoluciones[i][w].insert(i);
					}
				}
				//cout<< "w"<<w<<endl;
			}
			//cout << "i" << i<< endl;
		}
		cout << "ComputarMochila: RESULTADO: " << tPesos[stage.qtyNode][stage.capacityBag] << endl;
	} catch(string & error) {
		std::cout << "***ERROR***: "<< error << endl;
	}

	//Imprimo objetos en la mochila

	std::set<int> mochilaFinal;
	mochilaFinal.swap(tSoluciones[stage.qtyNode][stage.capacityBag]);


	for ( std::set<int>::const_iterator si = mochilaFinal.begin( ) ;
		 si != mochilaFinal.end( ) ; si++ ) {
	      std::cout << *si << "\n" ;
	   }
}
Mochila::~Mochila(){

}

