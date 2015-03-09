#pragma once
#include "Solucion.h"
class MergeSortS :
	public Solucion
{
public:
	MergeSortS();
	virtual void resolver();
	virtual void mezcla(vector<Solucion*>);
	virtual Solucion* getInstance();
	void setList(vector<int>);
	vector<int> getList();
	virtual ~MergeSortS();
private:
	vector<int> list;
};

