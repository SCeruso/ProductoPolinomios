#pragma once
#include "Monomio.h"
#include <vector>

using namespace std;

class Polinomio
{
protected:
	int grado_;
	int terminos_;
	vector<Monomio> polinomio_;

public:
	Polinomio();
	Polinomio(int[], int);

	int get_grado();
	int get_terminos();
	Monomio get_monomio(int);
	void setPolinomio(int[], int);
	Polinomio operator~();
	friend ostream& operator<< (ostream&, Polinomio&);
	~Polinomio();
};

