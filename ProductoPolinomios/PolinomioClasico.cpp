#include "PolinomioClasico.h"


PolinomioClasico::PolinomioClasico()
{
}


PolinomioClasico::PolinomioClasico(int v[], int t): Polinomio(v, t) {

}
PolinomioClasico::~PolinomioClasico()
{
}


Polinomio* PolinomioClasico::producto(Polinomio* p, Polinomio* q) {
	int *vec = new int[p->get_grado() + q->get_grado() + 1];
	int accum;
	Polinomio *result = NULL;
	int aux = 0;
	for (int i = 0; i <= p->get_grado() + q->get_grado(); i++) {
		accum = 0;
		for (int j = 0; j <= i; j++) {
			aux++;
			if (i - j < q->get_terminos() && j < p->get_terminos())
				accum += p->get_monomio(j).getCoeficiente() * q->get_monomio(i - j).getCoeficiente();
		}
		vec[i] = accum;
	}
	result = new Polinomio(vec, p->get_grado() + q->get_grado() + 1);
	delete vec;
//	cout << "Numero operaciones: " << aux << endl;
	return result;
}
/*
PolinomioClasico PolinomioClasico::operator*(PolinomioClasico& other) {
	int *vec = new int [grado_ + other.grado_ + 1];
	int accum;

	for (int i = 0; i <= grado_ + other.grado_; i++) {
		accum = 0;
		for (int j = 0; j <= i; j++) {
			if (i - j < other.terminos_ && j < terminos_)
				accum += polinomio_[j].getCoeficiente() * other.polinomio_[i - j].getCoeficiente();
		}
		vec[i] = accum;
	}

	return *new PolinomioClasico(vec, grado_ + other.grado_ + 1);
}*/