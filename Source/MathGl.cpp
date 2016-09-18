/*
 * MathGl.cpp
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#include "../Headers/MathGl.h"

namespace std {

MathGl::MathGl() {
	// TODO Auto-generated constructor stub

}

void MathGl::plot(map<pair<int,int>,int>* sample,string title){
	mglData y;
	//TODO esto puede llegar a ser muy ineficiente si nuestra muestra es muy grande
	double* x = new double[sample->size()];
	int i = 0;
	for(map<pair<int,int>,int>::iterator it = sample->begin(); it != sample->end(); ++it){
		x[i] = it->second;
		i++;
	}
	//cargamos a la funcion los valores
	y.Link(x,sample->size());
	//configuración de la imagen
	gr.SubPlot(1,1,0,"");
	gr.Title(title.c_str());
	gr.SetRanges(0,1000,0,200);
	gr.SetTicksTime('x',0);
	gr.Axis();
	gr.Grid("!","h=");
	gr.Box("r");
	//genera el gráfico
	gr.Plot(y);
	stringstream fileName;
	fileName << title << ".png";
	gr.WriteFrame(fileName.str().c_str());
}

MathGl::~MathGl() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
