#include "Animal.h"

Animal::Animal()
{
	pos = 1;
	type = und;
}

void Animal::setPos(int p, int d) {
	// d value greater then 0 indicates a positive movemnt
	if (d >= 0) {
		pos = pos + p;
	}
	// d value less then or equal to 0 indicates a negative movement
	if (d <= 0) {
		pos = pos - p;
	}

	// check if position is in bounds and fix if it isnt
	if (pos > 70) {
		pos = 70;
	}
	if (pos < 1) {
		pos = 1;
	}
}
int Animal::getPos() { return pos; }

void Animal::setType(types t) {
	type = t;
}

Animal::types Animal::getType() { return type; }

Animal::~Animal()
{
}
