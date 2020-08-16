#include<iostream>
using namespace std;

class Complex
{
	public:
		Complex(double=0,double=0);
		Complex add(Complex);
		Complex subtract(Complex);
		void printComplex();
		void setComplexNumber(double=0,double=0);
		
		
	private:
		double realPart;
		double imaginaryPart;
	
};
