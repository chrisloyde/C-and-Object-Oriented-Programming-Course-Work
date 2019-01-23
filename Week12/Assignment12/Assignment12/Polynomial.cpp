#include "Polynomial.h"



Polynomial::Polynomial()
{
	num = 0;
}

void Polynomial::addTerm(int co, int ex) {
	// creates a new term object
	Term t(co, ex);
	addTerm(t);
}

void Polynomial::addTerm(Term toAdd) {
	bool isAdded = false; // flag to check if term was added or not
	// loop through current terms to see if any have matching exponents with the one
	// to add.

	for (int i = 0; i < terms.size(); i++) {
		if (toAdd.getExponent() == terms.at(i).getExponent()) {
			// if matching, set the coefficient to the addition of the current
			// term to the to add term.
			terms.at(i).setCoefficient(terms.at(i).getCoefficient() + toAdd.getCoefficient());
			isAdded = true; // flag true
		}
		
	}
	if (!isAdded) {
		// if it doesn't match, push it into the vector
		terms.push_back(toAdd);
		++num;
	}
}

void Polynomial::setPolynomial(vector<Term> polynomial) {
	// free memory that exists in the current polynomial
	// then swap vectors with parameter vector and update size
	free();
	terms.swap(polynomial);
	num = polynomial.size();
}

vector<Term> Polynomial::getPolynomial() {
	return terms;
}

Polynomial Polynomial::operator+(const Polynomial &poly) {
	Polynomial ret;
	ret = *this;
	ret += poly;

	return ret;
}

Polynomial Polynomial::operator- (const Polynomial &poly) {
	Polynomial ret;
	ret = *this;
	ret -= poly;

	return ret;
}

Polynomial Polynomial::operator* (const Polynomial &poly) {
	Polynomial ret;
	ret = *this;
	ret *= poly;

	return ret;
}

Polynomial& Polynomial::operator= (const Polynomial &poly) {
	terms.clear(); // clear terms for this polynomial
	num = 0;
	// increment through parameter polynomial's terms and push them
	// to this object.
	for (auto term : poly.terms) {
		terms.push_back(Term(term.getCoefficient(), term.getExponent()));
		++num;
	}

	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &poly) {
	// addTerm function takes care of addition.
	for (auto term : poly.terms) {
		this->addTerm(term);
	}

	return *this;
}

Polynomial& Polynomial::operator-= (const Polynomial &poly) {
	for (auto term : poly.terms) {
		term.opposeSign(); // negate sign
		this->addTerm(term); // add term to this.
		term.opposeSign(); // reset negation
	}
	return *this;
}

Polynomial& Polynomial::operator*= (const Polynomial &poly) {
	// due to complexities of multiplication, creating a temporary polynomial and a temporary term to store values.
	Polynomial temp;
	Term tempTerm(0,0);
	// increment through both arrays using nested loops to multiply every value from this polynomial to every value
	// from the other polynomial
	for (auto term : terms) {
		for (auto termOther : poly.terms) {
			// multiply both coefficients and assign to tempTerm
			tempTerm.setCoefficient(term.getCoefficient() * termOther.getCoefficient());
			// add both exponents and assign to tempTerm
			tempTerm.setExponent(term.getExponent() + termOther.getExponent());
			// add the tempTerm to the temporary Polynomial (addTerm will handle duplicate exponents)
			temp.addTerm(Term(tempTerm.getCoefficient(), tempTerm.getExponent()));
		}
	}

	// set this Polynomial to the temporary ones.
	setPolynomial(temp.terms);
	// clear temp by setting it's Polynomial to an empty vector
	temp.setPolynomial(vector<Term>());

	return *this;
}

void Polynomial::printPolynomial() {
	for (auto term : terms) {
		term.printTerm();
		printf(" ");
	}
	printf("\n");
}

void Polynomial::free() {
	terms.clear();
	terms.resize(0);
	terms.shrink_to_fit();
	num = 0;
}

Polynomial::~Polynomial()
{
	free();
}
