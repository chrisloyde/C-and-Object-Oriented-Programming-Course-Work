#pragma once
#include <vector>
#include "Term.h"

using namespace std;
class Polynomial
{
public:
	Polynomial();
	void addTerm(int coefficient, int exponent);
	void setPolynomial(vector<Term> polynomial);
	vector<Term> getPolynomial();
	Polynomial operator+ (const Polynomial &polynomial);
	Polynomial operator- (const Polynomial &polynomial);
	Polynomial operator* (const Polynomial &polynomial);
	Polynomial& operator= (const Polynomial &polynomial);
	Polynomial& operator+= (const Polynomial &polynomial);
	Polynomial& operator-= (const Polynomial &polynomial);
	Polynomial& operator*= (const Polynomial &polynomial);

	void printPolynomial();
	void free();
	
	~Polynomial();
private:
	int num;
	vector<Term> terms;
	void addTerm(Term term);
};

