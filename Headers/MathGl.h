/*
 * MathGl.h
 *
 *  Created on: 18 de set. de 2016
 *      Author: jorge
 */

#ifndef MATHGL_H_
#define MATHGL_H_

#include <mgl2/mgl.h>
#include <string>
#include <map>

namespace std {

class MathGl {
private:
	mglGraph gr;
public:
	MathGl();
	void plot(map<pair<int,int>,int>* sample,string title);
	virtual ~MathGl();
};

} /* namespace std */

#endif /* MATHGL_H_ */
