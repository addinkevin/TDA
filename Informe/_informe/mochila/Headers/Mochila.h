#ifndef MOCHILA_H_
#define MOCHILA_H_
#include "../Headers/Parser.h"
#include "../Headers/Stage.h"
#include "../Headers/Node.h"
using namespace std;

class Mochila {
private:
	int** tPesos;
	void initMochila(int n, int w);
	Stage stage;
	int n;
	int w;

public:
	Mochila(Stage stage);
	~Mochila();

	// Devuelve el valor optimo obtenido.
	int computarMochila();

	// Devuelve un vector de los elementos que van a la mochila.
	vector<int> getItemsInBag();



};

#endif /* MOCHILA_H_ */
