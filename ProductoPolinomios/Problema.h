
#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include<vector>
#include<utility>
#include<iostream>
#include<vector>
#include"Solucion.h"
using namespace std;

class Problema {
public:
	Problema();
	virtual ~Problema();

	virtual bool isCasoMinimo() = 0;
	virtual vector<Problema*> descomponer() = 0;
	virtual void solver(Solucion* s);
};

#endif /* PROBLEMA_H_ */
