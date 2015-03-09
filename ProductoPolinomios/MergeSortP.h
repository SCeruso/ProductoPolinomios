#pragma once
#include "Problema.h"
#include"MergeSortS.h"
class MergeSortP :
	public Problema
{
public:
	MergeSortP();
	MergeSortP(int[], int);
	MergeSortP(vector<int>);
	virtual ~MergeSortP();

	virtual bool isCasoMinimo();
	virtual vector<Problema*> descomponer();
	virtual void solver(Solucion* s);
	
private:
	vector<int> list;
};

