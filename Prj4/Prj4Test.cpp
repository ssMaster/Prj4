/*
Simon Sharudin
CS331 - Project4
Due: June 16, 2015
*/



#include "polynomial.h"
#include <iostream>
using namespace std;

int main()
{
	int i;
	
	cout << "Start of default constructor, Polynomial(), tests..." << endl;
	Polynomial *a;
	Polynomial b, c;
	a = new Polynomial();
	show(a);
	cout << "End of Polynomial() tests." << endl << endl;
	
	cout << "Start of user-defined constructor, Polynomial(const char*), tests..." << endl;
	a = new Polynomial("-12 + 7x2 + 7x9 - 21x5 - 11x7");
	show(a);
	delete a;

	a = new Polynomial("-2x9 + 7x7 - 18x3 + 6x1 - 14");
	show(a);
	delete a;
	cout << "End of Polynomial(const char*) tests." << endl << endl;

	cout << "Start of >> and << tests..." << endl;
	cout << "Please enter: 3x9 - 6x7 - 18x3 + 6x1 + 14" << endl;
	cin >> b;
	cout << b << endl;
	cout << "Please enter: -4x7 + 12x4 + 9x1 - 9" << endl;
	cin >> c;
	cout << c << endl;
	cout << "End of >> and << tests." << endl << endl;
	
	cout << "Start of copy constructor tests..." << endl;
	Polynomial d(b);
	cout << d << endl;
	Polynomial e(c);
	cout << e << endl;
	cout << "End of copy tests...." << endl << endl;
	
	/*
	Polynomial f("3x9 - 6x7 - 18x3 + 6x1 + 14");
	Polynomial g("-2x9 + 7x7 - 18x3 + 6x2 - 11");
	Polynomial h("-4x7 + 12x4 + 9x1 - 9");

	cout << "Start of + tests..." << endl;
	e = f + g;
	cout << e << endl;
	e = f + h;
	cout << e << endl;
	cout << "End of + tests...." << endl << endl;

	cout << "Start of - tests..." << endl;
	e = f - g;
	cout << e << endl;
	e = f - h;
	cout << e << endl;
	cout << "End of - tests...." << endl << endl;

	cout << "Start of * tests..." << endl;
	e = f * g;
	cout << e << endl;
	e = f * h;
	cout << e << endl;
	cout << "End of * tests...." << endl << endl;

	cout << "Start of += tests..." << endl;
	e = f;
	e += g;
	cout << e << endl;
	e = f;
	e += h;
	cout << e << endl;
	cout << "End of += tests...." << endl << endl;

	cout << "Start of -= tests..." << endl;
	e = f;
	e -= g;
	cout << e << endl;
	e = f;
	e -= h;
	cout << e << endl;
	cout << "End of -= tests...." << endl << endl;

	cout << "Start of *= tests..." << endl;
	e = f;
	e *= g;
	cout << e << endl;
	e = f;
	e *= h;
	cout << e << endl;
	cout << "End of *= tests...." << endl << endl;

	cout << "Start of [] tests..." << endl;
	for (i = 9; i >= 0; i--)
		cout << "e[" << setw(1) << i << "] = " << setw(1) << e[i] << "\t";
	cout << endl;
	for (i = 9; i >= 0; i--)
		e[i] = i;
	for (i = 9; i >= 0; i--)
		cout << "e[" << setw(1) << i << "] = " << setw(1) << e[i] << "\t";
	cout << endl;
	cout << "End of [] tests...." << endl << endl;

	cout << "Start of () tests..." << endl;
	cout << "Evaluation = " << e(1) << endl;
	cout << "Evaluation = " << e(4) << endl;
	cout << "End of () tests...." << endl;*/

	return 0;
}


