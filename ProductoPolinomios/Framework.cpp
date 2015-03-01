
#include "Framework.h"

Framework::Framework() {
}

Framework::~Framework() {
}

void Framework::divideyVenceras(Problema* p, Solucion* s){
	if (p->isCasoMinimo()){
		p->solver(s);
	}
	else{
		vector<Problema*> subProblemas;
		vector<Solucion*> subSoluciones;
		subProblemas = p->descomponer();
		subSoluciones.resize(subProblemas.size());

		for (int i = 0; i < subProblemas.size(); i++) {
			subSoluciones[i] = s->getInstance();
			divideyVenceras(subProblemas[i], subSoluciones[i]);  //.n
		}
		s->mezcla(subSoluciones);
	}
};