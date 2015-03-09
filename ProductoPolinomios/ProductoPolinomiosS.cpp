#include "ProductoPolinomiosS.h"


ProductoPolinomiosS::ProductoPolinomiosS() : r(NULL)
{
}


ProductoPolinomiosS::~ProductoPolinomiosS()
{
	delete r;
}


void ProductoPolinomiosS::resolver(){
	cout << *r << endl;
}


void ProductoPolinomiosS::mezcla(vector<Solucion*> x){
	Polinomio* aux;
	Polinomio* aux2;
	Polinomio* aux3;
	Polinomio* res;

	aux = resta(((ProductoPolinomiosS*)x[1])->r, ((ProductoPolinomiosS*)x[0])->r, ((ProductoPolinomiosS*)x[2])->r);
	aux2 = desplazar(((ProductoPolinomiosS*)x[0])->r, ((ProductoPolinomiosS*)x[2])->r->get_terminos() + 1);//n
	aux3 = desplazar(aux, ((((ProductoPolinomiosS*)x[2])->r->get_terminos() + 1) / 2));// n / 2
	res = suma(aux3, aux2, ((ProductoPolinomiosS*)x[2])->r);

	delete aux;
	delete aux2;
	delete aux3;

	this->r = res;
}


Solucion* ProductoPolinomiosS::getInstance(){
	return new ProductoPolinomiosS();
}


void ProductoPolinomiosS::setPolinomio(Polinomio* sol){
	r = sol;
}


Polinomio* ProductoPolinomiosS::resta(Polinomio* x2, Polinomio* x1, Polinomio* x3){
	int size = max(max(x2->get_terminos(), x1->get_terminos()), x3->get_terminos());
	int *v = new int[size];
	Polinomio* res;

	for (int i = 0; i < size; i++) {
		if (i < x2->get_terminos() && i < x1->get_terminos() && i < x3->get_terminos())
			v[i] = x2->get_monomio(i).getCoeficiente() - x1->get_monomio(i).getCoeficiente() - x3->get_monomio(i).getCoeficiente();
		else if (i < x2->get_terminos() && i < x1->get_terminos())
			v[i] = x2->get_monomio(i).getCoeficiente() - x1->get_monomio(i).getCoeficiente();
		else if (i < x2->get_terminos() && i < x3->get_terminos())
			v[i] = x2->get_monomio(i).getCoeficiente() - x3->get_monomio(i).getCoeficiente();
	}

	res = new Polinomio(v, size);
	delete v;
	return res;
}


Polinomio* ProductoPolinomiosS::suma(Polinomio* x1, Polinomio* x2, Polinomio* x3) {
	int size = max(max(x2->get_terminos(), x1->get_terminos()), x3->get_terminos());
	int *v = new int[size];
	Polinomio* res;

	for (int i = 0; i < size; i++) {
		if (i < x2->get_terminos() && i < x1->get_terminos() && i < x3->get_terminos())
			v[i] = x2->get_monomio(i).getCoeficiente() + x1->get_monomio(i).getCoeficiente() + x3->get_monomio(i).getCoeficiente();
		else if (i < x2->get_terminos() && i < x1->get_terminos())
			v[i] = x2->get_monomio(i).getCoeficiente() + x1->get_monomio(i).getCoeficiente();
		else if (i < x2->get_terminos() && i < x3->get_terminos())
			v[i] = x2->get_monomio(i).getCoeficiente() + x3->get_monomio(i).getCoeficiente();
		else
			v[i] = x2->get_monomio(i).getCoeficiente();
	}

	res = new Polinomio(v, size);
	delete v;
	return res;
}
Polinomio* ProductoPolinomiosS::desplazar(Polinomio* p, int n){
	int *v = new int[p->get_terminos() + n];
	Polinomio* res;
	int j = 0;

	for (int i = 0; i < p->get_terminos() + n; i++) {
		if (i < n)
			v[i] = 0;
		else {
			v[i] = p->get_monomio(j).getCoeficiente();
			j++;
		}
	}
	res = new Polinomio(v, p->get_terminos() + n);
	delete v;
	return res;
}