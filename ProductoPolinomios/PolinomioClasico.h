#pragma once
#include "Polinomio.h"
class PolinomioClasico :
	public Polinomio
{
public:
	PolinomioClasico();
	PolinomioClasico(int[], int);

	static Polinomio* producto(Polinomio*, Polinomio*);
//	PolinomioClasico operator* (PolinomioClasico&);
	~PolinomioClasico();
};

