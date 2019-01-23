#pragma once
#include <iostream>
class Term
{
public:
	Term();
	Term(int coefficient, int exponent);
	void setCoefficient(int coefficient);
	void setExponent(int exponent);
	int getCoefficient();
	int getExponent();
	int opposeSign();
	void printTerm();
	~Term();
private:
	int c;
	int e;
};

