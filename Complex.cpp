#include<iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double rP,double iP)
{
	realPart=rP;
	imaginaryPart=iP;
}


Complex Complex::add(Complex n2)
{
	realPart=realPart+n2.realPart;
	imaginaryPart=imaginaryPart+n2.imaginaryPart;
	//Complex c(realPart,imaginaryPart);
	//return c;
	return *this;
}


Complex Complex::subtract(Complex n2)
{
	realPart=realPart-n2.realPart;
	imaginaryPart=imaginaryPart-n2.imaginaryPart;
	//Complex c(realPart,imaginaryPart);
	//return c;
	return *this;
}


void Complex::setComplexNumber(double rP,double iP)
{
	realPart=rP;
	imaginaryPart=iP;
	
}

void Complex::printComplex()
{
	cout<<"("<<realPart<<","<<imaginaryPart<<")";
}

