#include "Monomio.h"


Monomio::Monomio()
{
}


Monomio::Monomio(int coef, int exp) {
	coeficiente_ = coef;
	exponente_ = exp;
}
Monomio::~Monomio()
{
}


int Monomio::evaluar(int x)
{
	return (coeficiente_ * pow((float)x, (float)exponente_));
}


int Monomio::getCoeficiente()
{
	return coeficiente_;
}


int Monomio::getExponente()
{
	return exponente_;
}


void Monomio::setCoeficiente(int x)
{
	coeficiente_ = x;
}


void Monomio::setExponente(int x)
{
	exponente_ = x;
}


Monomio Monomio::operator + (const Monomio& other){
	return *(new Monomio(this->coeficiente_ + other.coeficiente_, this->exponente_));
}


Monomio Monomio::operator*(const Monomio& other) {
	return *(new Monomio(this->coeficiente_ * other.coeficiente_, this->exponente_ + other.exponente_));
}
std::ostream& operator << (std::ostream& os , Monomio& m){
	os << m.coeficiente_ << "x^" << m.exponente_;
	return os;
}


std::istream& operator >> (std::istream& is, Monomio& m){
	is >> m.coeficiente_;
	is >> m.exponente_;
	return is;
}