/*
Simon Sharudin
CS331 - Project4
Due: June 16, 2015
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <iomanip>
#include <cmath> 
#include <cstring>
using namespace std;

class Polynomial {

	friend istream& operator>>(istream& in, Polynomial& v);
	friend ostream& operator<<(ostream& out, const Polynomial& v);
	friend void show(Polynomial* p);

public:
	Polynomial();
	Polynomial(const Polynomial&);
	Polynomial(const char *);
	Polynomial operator+(const Polynomial&) const;
	Polynomial operator-(const Polynomial&) const;
	Polynomial operator*(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	int operator[](int) const;
	int& operator[](int);
	int operator()(int);

private:
	int coefficients_[10];
};

#endif