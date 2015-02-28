#include "PolinomioDyV.h"


PolinomioDyV::PolinomioDyV()
{
}


PolinomioDyV::~PolinomioDyV()
{
}


PolinomioDyV::PolinomioDyV(int v[], int t):Polinomio(v, t) {}


Polinomio* PolinomioDyV::producto(Polinomio* p, Polinomio* q){
	//Hacerlos de igual tamaño
	int a = p->get_terminos();
	int count = 0;
	Polinomio* p2 = multiplicar(p, q, a, count);
	cout << "Count para DyV: " << count << endl;
	return p2;
}


Polinomio* PolinomioDyV::multiplicar(Polinomio* p, Polinomio* q, int n, int &count){
	Polinomio *ph, *pl, *qh, *ql;
	ph = pl = qh = ql = NULL;
	Polinomio *rl, *rh, *rm;
	rl = rh = rm = NULL;
	Polinomio aux;
	Polinomio *s1, *s2;
	Polinomio* sumaparcial1;
	Polinomio* sumaparcial2;
	Polinomio* resAux;
	Polinomio* res;
	int despl;

	if (n == 1) {
		int v[1];
		v[0] = p->get_monomio(0).getCoeficiente() * q->get_monomio(0).getCoeficiente();
		count++;
		return new Polinomio(v, 1);
	}
	else {
		divide(p, q, qh, ql, ph, pl);
		despl = pl->get_terminos() + ql->get_terminos();

		count += ph->get_terminos();

		s1 = suma(pl, ph);
		s2 = suma(ql, qh);

		count += qh->get_terminos();
		count += ph->get_terminos();

		rl = multiplicar(pl, ql, pl->get_terminos(), count);
		rh = multiplicar(ph, qh, ph->get_terminos(), count);
		rm = multiplicar(s1, s2, s1->get_terminos(), count);
		aux = ~(*rl);
		sumaparcial1 = suma(rm, &aux);
		aux = ~(*rh);
		sumaparcial2 = suma(sumaparcial1, &aux);
		count += rl->get_terminos();
		count += rh->get_terminos();
		count += rm->get_terminos();
		count += sumaparcial1->get_terminos();

		delete sumaparcial1;

		sumaparcial1 = desplazar(sumaparcial2, ((n / 2)));
		count += sumaparcial2->get_terminos() + n / 2;
		delete sumaparcial2;

		sumaparcial2 = desplazar(rh,despl);

		count += rh->get_terminos() + despl;

		resAux = suma(sumaparcial1, sumaparcial2);
		count += sumaparcial2->get_terminos();
		res = suma(resAux, rl);
		count += resAux->get_terminos();
		delete resAux;
		delete rl;
		delete rh; 
		delete rm;
		//**
		delete pl;
		delete ph;
		delete ql;
		delete qh;
	
		count += 8;
		return res;
	}

}

Polinomio* PolinomioDyV::desplazar(Polinomio* p, int n){
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
void  PolinomioDyV::divide(Polinomio* p, Polinomio* q, Polinomio* &qh, Polinomio* &ql, Polinomio* &ph, Polinomio* &pl) {
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

Polinomio* PolinomioDyV::suma(Polinomio* p, Polinomio* q){
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

	res = new Polinomio(v,size);
	delete v;

	return res;
}