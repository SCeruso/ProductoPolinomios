#include "ProductoPolinomiosP.h"


ProductoPolinomiosP::ProductoPolinomiosP()
{
}


ProductoPolinomiosP::ProductoPolinomiosP(Polinomio* a, Polinomio* b): p(a), q(b){

}


ProductoPolinomiosP::~ProductoPolinomiosP()
{
	delete p;
	delete q;
}


void ProductoPolinomiosP::solver(Solucion* s) {
	int v[1];

	v[0] =  p->get_monomio(0).getCoeficiente() * q->get_monomio(0).getCoeficiente();
	((ProductoPolinomiosS*)s)->setPolinomio(new Polinomio(v, 1));
}


bool ProductoPolinomiosP::isCasoMinimo(){
	if (p->get_terminos() == 1 && q->get_terminos() == 1)
		return true;
	else
		return false;
}


vector<Problema*> ProductoPolinomiosP::descomponer(){
	Polinomio *pl, *ph, *ql, *qh, *s1, *s2;
	vector<Problema*> res;

	divide(p, q, qh, ql, ph, pl);
	s1 = suma(ph, pl);
	s2 = suma(qh, ql);

	res.push_back(new ProductoPolinomiosP(ph, qh));
	res.push_back(new ProductoPolinomiosP(s1, s2));
	res.push_back(new ProductoPolinomiosP(pl, ql));
	
	return res;
}


Polinomio* ProductoPolinomiosP::suma(Polinomio* p, Polinomio* q){
	int size = std::max(p->get_terminos(), q->get_terminos());
	int *v = new int[size];
	Polinomio* res;

	for (int i = 0; i < size; i++) {
		if (i < p->get_terminos() && i < q->get_terminos())
			v[i] = p->get_monomio(i).getCoeficiente() + q->get_monomio(i).getCoeficiente();
		else if (i < p->get_terminos())
			v[i] = p->get_monomio(i).getCoeficiente();
		else if (i < q->get_terminos())
			v[i] = q->get_monomio(i).getCoeficiente();
	}

	res = new Polinomio(v, size);
	delete v;

	return res;
}


void  ProductoPolinomiosP::divide(Polinomio* p, Polinomio* q, Polinomio* &qh, Polinomio* &ql, Polinomio* &ph, Polinomio* &pl) {
	int mp = p->get_terminos() / 2;
	int *vph = new int[p->get_terminos() - mp];
	int *vqh = new int[p->get_terminos() - mp];
	int *vpl = new int[mp];
	int *vql = new int[mp];
	int i;


	for (i = 0; i < mp; i++) {
		vpl[i] = p->get_monomio(i).getCoeficiente();
		vql[i] = q->get_monomio(i).getCoeficiente();
		vph[i] = p->get_monomio(i + mp).getCoeficiente();
		vqh[i] = q->get_monomio(i + mp).getCoeficiente();
	}
	if ((p->get_terminos() % 2) != 0) {
		vph[i] = p->get_monomio(i + mp).getCoeficiente();
		vqh[i] = q->get_monomio(i + mp).getCoeficiente();
	}
	qh = new Polinomio(vqh, p->get_terminos() - mp);
	ql = new Polinomio(vql, mp);
	ph = new Polinomio(vph, p->get_terminos() - mp);
	pl = new Polinomio(vpl, mp);

	delete vph;
	delete vpl;
	delete vqh;
	delete vql;
}

Polinomio ProductoPolinomiosP::getP() { return *p; }


Polinomio ProductoPolinomiosP::getQ() { return *q; }