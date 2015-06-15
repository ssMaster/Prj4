/*
Simon Sharudin
CS331 - Project4
Due: June 16, 2015
*/


#include "Polynomial.h"
#include <vector>

// Default Constructor
Polynomial::Polynomial(){
	// Initialize array to zero
	for (int i = 0; i < 10; i++){
		coefficients_[i] = 0;
	}
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial& p){
	coefficients_[10];
	for (int i = 0; i < 10; i++){
		coefficients_[i] = p.coefficients_[i];
	}
}

// User-defined Constructor - Creates an object with the given string polynomial
Polynomial::Polynomial(const char* ps){
	string s = ps;
	string term;
	vector<string> terms;
	vector<string> coeff;
	vector<string> sub;

	// Initialize array to zero
	for (int i = 0; i < 10; i++){
		coefficients_[i] = 0;
	}

	// Get the terms
	string temp = "";
	for (string::iterator it = s.begin(); it != s.end(); it++){
		if (*it != ' '){
			term = term + *it;
		}
		else{
			terms.push_back(term);
			term = "";
		}

	}
	terms.push_back(term);	// add the final term to the vector

	// ========================================================

	int index;
	for (vector<string>::iterator it = terms.begin(); it != terms.end(); it++){
		if ((*it).compare("+") == 0 || (*it).compare("-") == 0 || (*it).compare("*") == 0 || (*it).compare("+=") == 0 || (*it).compare("-=") == 0 || (*it).compare("*=") == 0){
			//cout << "Operator found!" << endl;
		}
		else{
			//cout << "The term is:\t" << *it << endl;

			index = (*it).find('x');

			coeff.push_back((*it).substr(0, index));
			if (index == -1){
				sub.push_back("0");
			}
			else{
				sub.push_back((*it).substr(index + 1, (*it).size()));
			}
		}
	}

	/*cout << endl;
	for (vector<string>::iterator it = coeff.begin(); it != coeff.end(); it++){
		cout << "The coeff is:\t\t" << *it << endl;
	}

	cout << endl;
	for (vector<string>::iterator it = sub.begin(); it != sub.end(); it++){
		cout << "The subscript is:\t\t\t" << *it << endl;
	}*/

	// ======================================================

	// Assign each coefficient in the array to its power subscript
	
	vector<string>::iterator sub_it = sub.begin();
	for (vector<string>::iterator coeff_it = coeff.begin(); coeff_it != coeff.end(); coeff_it++, sub_it++){
		int c, s;
		c = stoi(*coeff_it);
		s = stoi(*sub_it);
		coefficients_[s] = c;
	}

	// =========
	/*cout << endl;
	for (int i = 0; i < 10; i++){
		cout << coefficients_[i] << " x " << i << endl;
	}*/
}

istream& operator>>(istream& in, Polynomial& v){
	char c[100];
	in.getline(c, 100);
	v = Polynomial(c);

	return in;
}

ostream& operator<<(ostream& out, const Polynomial& v){
	int size = 10;

	for (int i = size - 1; i >= 0; i--){
		if (v.coefficients_[i] != 0){
			if (i == 0){	
				out << "Term is: " << v.coefficients_[i] << endl;
			}
			else{
				out << "Term is: " << v.coefficients_[i] << "x" << i << endl;
			}
		}
	}

	return out;
}

void show(Polynomial* p) {
	cout << "Coefficients are: " << p->coefficients_[0];
	for (int i = 1; i<10; i++) {
		cout << "," << p->coefficients_[i];
	}
	cout << endl;
}


// ===================================

// Overloaded + operator
Polynomial Polynomial::operator+(const Polynomial& poly) const{
	Polynomial ans;

	for (int i = 0; i < 10; i++){
		ans.coefficients_[i] = coefficients_[i] + poly.coefficients_[i];
		cout << coefficients_[i] << " + " << poly.coefficients_[i] << " = " << ans.coefficients_[i] << "\tPower: " << i << endl;
	}

	return ans;
}
/*
Polynomial Polynomial::operator-(const Polynomial&) const{

}

Polynomial Polynomial::operator*(const Polynomial&){

}

Polynomial& Polynomial::operator+=(const Polynomial&){

}

Polynomial& Polynomial::operator-=(const Polynomial&){

}

Polynomial& Polynomial::operator*=(const Polynomial&){

}

// ===================================

int Polynomial::operator[](int) const{

}

int& Polynomial::operator[](int){

}

int Polynomial::operator()(int){

}
*/