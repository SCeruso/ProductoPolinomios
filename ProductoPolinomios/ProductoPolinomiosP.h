#pragma once
#include "Problema.h"
#include "Polinomio.h"
#include <algorithm>
#include "ProductoPolinomiosS.h"
class ProductoPolinomiosP :
	public Problema
{
private:
	Polinomio* p;
	Polinomio* q;
public:
	ProductoPolinomiosP();
	ProductoPolinomiosP(Polinomio*, Polinomio*);
	virtual ~ProductoPolinomiosP();

	virtual bool isCasoMinimo();
	virtual vector<Problema*> descomponer();
	virtual void solver(Solucion* s);

	Polinomio getP();
	Polinomio getQ();

private:
	void divide(Polinomio*, Polinomio*, Polinomio* &, Polinomio* &, Polinomio* &, Polinomio* &);
	Polinomio* suma(Polinomio*, Polinomio*);
};

