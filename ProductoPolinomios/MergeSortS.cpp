#include "MergeSortS.h"


MergeSortS::MergeSortS()
{
}


MergeSortS::~MergeSortS()
{
}


void MergeSortS::resolver(){
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " ";
	}
	cout << endl;
}
void MergeSortS::mezcla(vector<Solucion*> parts){
	vector<int> res;
	int indx1 = 0;
	int indx2 = 0;

	while (indx1 < ((MergeSortS*)parts[0])->getList().size() && indx2 < ((MergeSortS*)parts[1])->getList().size()) {
		if (((MergeSortS*)parts[0])->getList()[indx1] < ((MergeSortS*)parts[1])->getList()[indx2]){
			res.push_back(((MergeSortS*)parts[0])->getList()[indx1]);
			indx1++;
		}
		else {
			res.push_back(((MergeSortS*)parts[1])->getList()[indx2]);
			indx2++;
		}
	}
	if (indx1 < ((MergeSortS*)parts[0])->getList().size()) {
		while (indx1 < ((MergeSortS*)parts[0])->getList().size()) {
			res.push_back(((MergeSortS*)parts[0])->getList()[indx1]);
			indx1++;
		}
	}
	else {
		while (indx2 < ((MergeSortS*)parts[1])->getList().size()) {
			res.push_back(((MergeSortS*)parts[1])->getList()[indx2]);
			indx2++;
		}
	}

	list = res;
}
Solucion* MergeSortS::getInstance(){
	return new MergeSortS();
}
void MergeSortS::setList(vector<int> l){
	list = l;
}

vector<int> MergeSortS::getList() { return list; }