/*
Exercise 10.11 on page 495-496

Exercise 10.11 (Polynomial Class):
	Class: Polynomial
	Data: Array of terms (each term has coefficient and exponent) ex. 2x^4
		  set and get functions.
		  constructor and deconstructor
	Capabilities: 
		Overload multiple operators:
			+, -, assign (assign one operator to another), *, +=, -=, *=
		
*/

#include <iostream>
#include "Polynomial.h"

int main() {

	Polynomial pA;
	Polynomial pB;
	Polynomial pC;

	pA.addTerm(2,0);
	pA.addTerm(2, 1);
	pA.addTerm(2, 2);

	pB.addTerm(3, 0);
	pB.addTerm(3, 1);
	pB.addTerm(3, 2);

	printf("Polynomial A: "); pA.printPolynomial();
	printf("Polynomial B: "); pB.printPolynomial();

	printf("\n");

	// Didn't write display cases for +=, -=, *= operators because
	// the +, -, and = operators use the +=, -=, *= operators to process the output.

	pC = pA;
	printf("Assignment C = A: "); pC.printPolynomial();
	pC = pA + pB;
	printf("Addition C = A + B: ");  pC.printPolynomial();
	pC = pA - pB;
	printf("Subtraction C = A - B: "); pC.printPolynomial();
	pC = pA * pB;
	printf("Multiplication C = A * B: ");  pC.printPolynomial();

	printf("\nUnchanged Polynomials after operations\n");
	pA.printPolynomial();
	pB.printPolynomial();

	pA.free();
	pB.free();
	pC.free();

	getchar();
	return 0;
}