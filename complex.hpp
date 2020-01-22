#include<iostream>
using namespace std;

class Complex
{
	double real,imag;
	public:
		Complex(double,double);
		void print();
		friend Complex add(const Complex&,const Complex&);
		friend Complex multiply(const Complex&,const Complex&); 
};

Complex::Complex(double aaa,double bbb)
{
	real=aaa;
	imag=bbb;
}

void Complex::print()
{
	if(imag==0)
	cout << real << endl;
	else
	cout << real << ((imag>0)?"+":"") << imag << "i" << endl;
}

Complex Complex::add(const Complex& aaa,const Complex& bbb)
{
	Complex ccc(aaa.real+bbb.real,aaa.imag+bbb.imag);
	return ccc;
}

Complex Complex::multiply(const Complex& aaa,const Complex& bbb)
{
	double ccc=aaa.real*bbb.real-aaa.imag*bbb.imag;
	double ddd=aaa.real*bbb.imag+aaa.imag*bbb.real;
	Complex eee(ccc,ddd);
	return eee;
}
