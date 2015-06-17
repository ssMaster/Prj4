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
	vector<string> ops;

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
			ops.push_back(*it);
		}
		else{
			cout << "The term is:\t" << *it << endl;

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

	// ================================================ Convert subtraction of a term to a negative coefficient

	vector<string>::iterator op_it = ops.begin();
	vector<string>::iterator coeff_it = coeff.begin();
	
	coeff_it++;
	while (coeff_it != coeff.end()){
		if ((*op_it).compare("-") == 0){
			*coeff_it = "-" + *coeff_it;
		}
		coeff_it++;
		op_it++;
	}

	cout << endl;
	for (vector<string>::iterator it = ops.begin(); it != ops.end(); it++){
		cout << "The operator is: " << *it << endl;
	}

	// ======================================================

	// Assign each coefficient in the array to its power subscript
	vector<string>::iterator sub_it = sub.begin();
	for (vector<string>::iterator coeff_it = coeff.begin(); coeff_it != coeff.end(); coeff_it++, sub_it++){
		int c, s;
		c = stoi(*coeff_it);
		s = stoi(*sub_it);
		coefficients_[s] = c;
	}

}

// Overloaded >> operator for polynomials
istream& operator>>(istream& in, Polynomial& v){
	char c[100];
	in.getline(c, 100);
	v = Polynomial(c);

	return in;
}

// Overloaded << operator for polynomials
ostream& operator<<(ostream& out, const Polynomial& v){
	int size = 10;

	for (int i = size - 1; i >= 0; i--){
		if (v.coefficients_[i] != 0){
			if (i == 0){	
				out << v.coefficients_[i];
			}
			else{
				if (v.coefficients_[i] >= 0){
					//out << v.coefficients_[i] << "x" << i << " + ";
				}
				else{
					//out << v.coefficients_[i] << "x" << i << " - ";
				}
				out << v.coefficients_[i] << "x" << i << " + ";

			}
		}
	}

	return out;
}

// Display the coefficients of the polynomial
void show(Polynomial* p) {
	cout << "Coefficients are: " << p->coefficients_[0];
	for (int i = 1; i<10; i++) {
		cout << "," << p->coefficients_[i];
	}
	cout << endl;
}

// Overloaded + operator for adding polynomials
Polynomial Polynomial::operator+(const Polynomial& poly) const{
	Polynomial ans;

	for (int i = 0; i < 10; i++){
		ans.coefficients_[i] = coefficients_[i] + poly.coefficients_[i];
	}

	return ans;
}

// Overloaded - operator for subtracting polynomials
Polynomial Polynomial::operator-(const Polynomial& poly) const{
	Polynomial ans;

	for (int i = 0; i < 10; i++){
		ans.coefficients_[i] = coefficients_[i] - poly.coefficients_[i];
	}

	return ans;
}

// Overloaded * operator for multiplying polynomials
Polynomial Polynomial::operator*(const Polynomial& poly){
	Polynomial ans;

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if ((i + j) <= 9){
				ans.coefficients_[i + j] += coefficients_[i] * poly.coefficients_[j];
			}
		}
	}

	return ans;
}

// Overloaded += operator for polynomials
Polynomial& Polynomial::operator+=(const Polynomial& poly){
	for (int i = 0; i < 10; i++){
		(*this).coefficients_[i] = (*this).coefficients_[i] + poly.coefficients_[i];
	}

	return *this;
}

// Overloaded -= operator for polynomials
Polynomial& Polynomial::operator-=(const Polynomial& poly){
	for (int i = 0; i < 10; i++){
		(*this).coefficients_[i] = (*this).coefficients_[i] - poly.coefficients_[i];
	}

	return *this;
}

// Overloaded *= operator for polynomials
Polynomial& Polynomial::operator*=(const Polynomial& poly){
	Polynomial ans;

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if ((i + j) <= 9){
				ans.coefficients_[i + j] += coefficients_[i] * poly.coefficients_[j];
			}
		}
	}

	return ans;
}

/*
Get the coefficient for a particular power of the polynomial as const
*/
int Polynomial::operator[](int index) const{
	return coefficients_[index];
}

/*
Set the coefficient for a particular power of the polynomial
*/
int& Polynomial::operator[](int index){
	return coefficients_[index];
}

/*
Evaluation of a polynomial
*/
int Polynomial::operator()(int x){
	int ans = 0;

	for (int i = 0; i < 10; i++){
		if (i == 0){
			ans += coefficients_[i];
		}
		else if (i == 1){
			ans += coefficients_[i] * x;
		}
		else{
			ans += coefficients_[i] * pow(x, i);
		}
	}

	return ans;
}
