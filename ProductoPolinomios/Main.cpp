#include "PolinomioClasico.h"
#include "PolinomioDyV.h"
#include <time.h>

int main(void) {
	int a[25000]; //= { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	int timea;

	for (int i = 0; i < 25000; i++)
		a[i] = i;


	Polinomio *p1;
	Polinomio *p2;

	for (int i = 10; i < 20; i++) {
		timea = time(NULL);
		cout << "Con algoritmo clasico, tamanio " << i * 100 << ": ";

		p1 = new Polinomio(a, (i ) * 100);
		p2 = new Polinomio(a, (i) * 100);
		
		PolinomioClasico::producto(p1, p2);
		timea = time(NULL) - timea;
	
		cout << timea << endl;

		cout << "Con algoritmo DyV, tamanio " << i*1000 << ": ";
		timea = time(NULL);
	
		PolinomioDyV::producto(p1, p2);
		
		timea = time(NULL) - timea;

		cout << timea << endl;

		delete p1;
		delete p2;
	}
	
	system("pause");
	
}