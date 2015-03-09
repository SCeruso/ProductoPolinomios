#include "MergeSortP.h"


MergeSortP::MergeSortP()
{
}


MergeSortP::MergeSortP(int v[], int n) {
	for (int i = 0; i < n; i++)
		list.push_back(v[i]);
}

MergeSortP::MergeSortP(vector<int> v) {
	list = v;
}

MergeSortP::~MergeSortP()
{
}


bool MergeSortP::isCasoMinimo(){
	if (list.size() == 1)
		return true;
	else
		return false;
}
vector<Problema*> MergeSortP::descomponer(){
	vector<Problema*> res;
	int mid = list.size() / 2;
	vector<int> aux;
	
	for (int i = 0; i < mid; i++)
		aux.push_back(list[i]);
	res.push_back(new MergeSortP(aux));
	aux.clear();
	for (int i = mid; i < list.size(); i++)
		aux.push_back(list[i]);
	res.push_back(new MergeSortP(aux));
	return res;
}
void MergeSortP::solver(Solucion* s){
	((MergeSortS*)s)->setList(list);
}