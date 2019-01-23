#include "Term.h"

Term::Term() {
	setCoefficient(0);
	setExponent(0);
}

Term::Term(int co, int ex) {
	setCoefficient(co);
	setExponent(ex);
}

void Term::setCoefficient(int co) {
	c = co;
}

void Term::setExponent(int ex) {
	e = ex;
}

int Term::getCoefficient() {
	return c;
}

int Term::getExponent() {
	return e;
}


int Term::opposeSign() {
	// multiply by negative 1 which will switch positive numbers to negative
	// and negative numbers to positive.
	c *= -1;
	return c;
}

void Term::printTerm() {
	printf("%dx^%d", getCoefficient(), getExponent());
}

Term::~Term() {
	e = 0;
	c = 0;
}
