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
	cout << "ComputarMochila: start" << endl;
	try{
		int tabla[stage.qtyNode+1][stage.capacityBag+1];
		for(int i=0;i<=stage.capacityBag;i++)
			tabla[0][i] = 0;

		for(int i=1; i<=stage.qtyNode; i++){
			for(int w=0;w<=stage.capacityBag;w++){
				int weight = stage.getNode(i-1)->weight;
				int valor = stage.getNode(i-1)->valor;
				if(w < weight){
					tabla[i][w] = tabla[i-1][w];
				}
				else{
					if(tabla[i-1][w] > (valor + tabla[i-1][w-weight]))
						tabla[i][w] = tabla[i-1][w];
					else
						tabla[i][w] = valor + tabla[i-1][w-weight];
				}
				//cout<< "w"<<w<<endl;
			}
			//cout << "i" << i<< endl;
		}
		cout << "ComputarMochila: RESULTADO: " << tabla[stage.qtyNode][stage.capacityBag] << endl;
	} catch(string & error) {
		std::cout << "***ERROR***: "<< error << endl;
	}
}
Mochila::~Mochila(){

}

