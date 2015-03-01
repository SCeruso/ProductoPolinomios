#pragma once
#include "Polinomio.h"
#include "Solucion.h"
#include <algorithm>
class ProductoPolinomiosS :
	public Solucion
{
private: 
	Polinomio* r;
	int despl;
public:
	ProductoPolinomiosS();
	virtual ~ProductoPolinomiosS();

	virtual void resolver();
	virtual void mezcla(vector<Solucion*>);
	virtual Solucion* getInstance();
	void setPolinomio(Polinomio*);
private:
	Polinomio* resta(Polinomio*, Polinomio*, Polinomio*);
	Polinomio* suma(Polinomio*, Polinomio*, Polinomio*);
	Polinomio* desplazar(Polinomio*, int);
};

