#include "PolinomioClasico.h"
#include "PolinomioDyV.h"
#include <time.h>
#include "Framework.h"
#include "ProductoPolinomiosP.h"
#include "ProductoPolinomiosS.h"

int main(void) {
	int a[5000]; //= { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	int timea;

	for (int i = 1; i < 5000; i++)
		a[i - 1] = i;


	Polinomio *p1;
	Polinomio *p2;

	p1 = new Polinomio(a, 5);
	p2 = new Polinomio(a, 5);

	Problema* problem = new ProductoPolinomiosP(p1, p2);
	Solucion* s = new ProductoPolinomiosS();
	Framework* f = new Framework();

	f->divideyVenceras(problem, s);

	s->resolver();
	cout << *PolinomioClasico::producto(p1, p2) << endl;
	/*for (int i = 1; i < 2; i++) {
		
		p1 = new Polinomio(a, (i)* 10000);
		p2 = new Polinomio(a, (i)* 10000); 
		/*timea = time(NULL);
		cout << "Con algoritmo clasico, tamanio " << i * 100 << ": ";

		
		
		PolinomioClasico::producto(p1, p2);
		timea = time(NULL) - timea;
	
		cout << timea << endl;
		*/
		/*cout << "Con algoritmo DyV, tamanio " << i*1000 << ": ";
		timea = time(NULL);
	
		PolinomioDyV::producto(p1, p2);
		
		timea = time(NULL) - timea;

		cout << timea << endl;

		delete p1;
		delete p2;
	*/
	
	system("pause");
	
}