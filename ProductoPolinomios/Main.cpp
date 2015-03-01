#include "PolinomioClasico.h"
#include "PolinomioDyV.h"
#include <time.h>
#include "Framework.h"
#include "ProductoPolinomiosP.h"
#include "ProductoPolinomiosS.h"

int main(void) {
	int a[10000]; 
	int timea;
	Polinomio *p1;
	Polinomio *p2;
	Problema* problem;
	Solucion* s;
	Framework* f;

	for (int i = 1; i <= 10000; i++)
		a[i - 1] = i;

	for (int i = 1; i < 10; i++) {
		p1 = new Polinomio(a, i * 1000);
		p2 = new Polinomio(a, i * 1000);
		problem = new ProductoPolinomiosP(p1, p2);
		s = new ProductoPolinomiosS();
		f = new Framework();
		timea = time(NULL);
		f->divideyVenceras(problem, s);
		cout << "Con DYV tarda: " << time(NULL) - timea << " segundos" << endl;
		timea = time(NULL);
		PolinomioClasico::producto(p1, p2);
		cout << "Con Clasico tarda: " << time(NULL) - timea<< " segundos" << endl;

	
		delete problem;
		delete s;
		delete f;
	}	
	system("pause");
	
}