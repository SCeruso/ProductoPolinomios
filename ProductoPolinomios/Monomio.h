#pragma once
#include <math.h>
#include<iostream>

class Monomio
{
private: 
	int coeficiente_;
	int exponente_;
public:
	Monomio();
	Monomio(int, int);

	int evaluar(int);
	int getCoeficiente();
	int getExponente();
	void setCoeficiente(int);
	void setExponente(int);

	Monomio operator+(const Monomio& other);
	Monomio operator*(const Monomio& other);
	friend std::ostream& operator<<(std::ostream&, Monomio&);
	friend std::istream& operator>>(std::istream&, Monomio&);
	~Monomio();
};


