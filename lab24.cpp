#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator+(double x,const ComplexNumber &c){
	return ComplexNumber(x+c.real,c.imag);
}

ComplexNumber operator-(double x,const ComplexNumber &c){
	return ComplexNumber(x-c.real,-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
}

ComplexNumber operator*(double x,const ComplexNumber &c){
	return ComplexNumber(x*c.real,x*c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber((real*c.real+imag*c.imag)/(c.real*c.real+c.imag*c.imag),(imag*c.real-c.imag*real)/(c.real*c.real+c.imag*c.imag));
}

ComplexNumber operator/(double real,const ComplexNumber &c){
	return ComplexNumber((real*c.real)/(c.real*c.real+c.imag*c.imag),(-c.imag*real)/(c.real*c.real+c.imag*c.imag));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real==c.real&&imag==c.imag)
		return true;
	return false;
}

ComplexNumber operator==(double x,const ComplexNumber &c){
	if(x==c.real&&0==c.imag)
		return true;
	return false;
}

double ComplexNumber::abs(){
	return sqrt(real*real+imag*imag);
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/M_PI;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
	if(c.real!=0){
		if (c.imag>0)
			return os<<c.real<<"+"<<c.imag<<"i";
		else if (c.imag==0)
			return os<<c.real;
		else
			return os<<c.real<<c.imag<<"i";
	}
	else{
		if (c.imag>0)
			return os<<c.imag<<"i";
		else if (c.imag==0)
			return os<<0;
		else
			return os<<c.imag<<"i";
	}
}

