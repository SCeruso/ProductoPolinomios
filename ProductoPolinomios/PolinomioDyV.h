#pragma once
#include "Polinomio.h"
#include <algorithm>

class PolinomioDyV :
	public Polinomio
{
public:
	PolinomioDyV();
	PolinomioDyV(int[], int);

	static Polinomio* producto(Polinomio*, Polinomio*);
	virtual ~PolinomioDyV();

private:
	static Polinomio* multiplicar(Polinomio*, Polinomio*, int, int&);
	static void  divide(Polinomio*, Polinomio*, Polinomio*&, Polinomio*&, Polinomio*&, Polinomio*&);
	static Polinomio* suma(Polinomio*, Polinomio*);
	static Polinomio* desplazar(Polinomio*, int);
};

