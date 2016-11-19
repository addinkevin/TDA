#include "../Headers/Mochila.h"
using namespace std;

Mochila::Mochila(Stage stage){
	this->stage = stage;
	this->n = this->stage.qtyNode;
	this->w = this->stage.capacityBag;
	this->initMochila(n,w);
}

void Mochila::initMochila(int n, int w) {
	this->tPesos = new int*[n+1];
	for(int i = 0; i < n+1; ++i) {
		tPesos[i] = new int[w + 1];
	}


	for (int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			tPesos[i][j] = 0;
		}
	}
}

int Mochila::computarMochila(){
	for(int i=1; i<=stage.qtyNode; i++){
		for(int w=0;w<=stage.capacityBag;w++){
			int weight = stage.getNode(i-1).weight;
			int valor = stage.getNode(i-1).valor;
			if(w < weight){
				tPesos[i][w] = tPesos[i-1][w];
			}
			else{
				if(tPesos[i-1][w] > (valor + tPesos[i-1][w-weight])){
					tPesos[i][w] = tPesos[i-1][w];
				}
				else{
					tPesos[i][w] = valor + tPesos[i-1][w-weight];
				}
			}
		}
	}

	return tPesos[n][w];
}

Mochila::~Mochila(){
	for(int i = 0; i < this->n+1; ++i) {
		delete [] tPesos[i];
	}
	delete [] tPesos;
}

vector<int> Mochila::getItemsInBag() {
	vector<int> itemsInBag;

	int weight = this->w;

	for (int i = this->n; i >= 1; i--) {
		if (this->tPesos[i][weight] != this->tPesos[i-1][weight]) {
			// Se incluyo el item ya que mejoro la solución
			itemsInBag.push_back(i);
			weight = weight - stage.getNode(i-1).weight;
		}
	}

	return itemsInBag;
}

