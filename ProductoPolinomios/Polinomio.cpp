#include "Polinomio.h"


Polinomio::Polinomio() :grado_(0), terminos_(0)
{
	polinomio_.resize(0);
}


Polinomio::Polinomio(int v[], int tam) {
	
	setPolinomio(v, tam);
}
Polinomio::~Polinomio()
{
}

int Polinomio::get_grado() { return grado_; }


int Polinomio::get_terminos() { return terminos_; }


Monomio Polinomio::get_monomio(int i) { return polinomio_[i]; }


Polinomio Polinomio::operator~() {
	int *v = new int[terminos_];

	for (int i = 0; i < terminos_; i++) {
		v[i] = -polinomio_[i].getCoeficiente();
	}
	Polinomio res(v, terminos_);
	delete v;
	return res;
}

void Polinomio::setPolinomio(int *v , int tam){
	Monomio dummy;

	for (int i = 0; i < tam; i++) {
		dummy.setCoeficiente(v[i]);
		dummy.setExponente(i);
		polinomio_.push_back(dummy);
	}
	terminos_ = tam;
	grado_ = tam - 1;
}


ostream& operator<< (ostream& os, Polinomio& p) {
	if (p.terminos_ >= 1)
		os << p.polinomio_[0];
	for (int i = 1; i < p.terminos_; i++) {
		os << " + " << p.polinomio_[i];
	}
	return os;
}