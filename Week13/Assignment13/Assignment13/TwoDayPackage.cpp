#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(double flatFee)
{
	if (flatFee < 0) {
		fee = 0;
	} 
	else {
		fee = flatFee;
	}
}

double TwoDayPackage::calculateCost() {
	// fee is a flat fee
	// calculated by (fee + (weight * ounces))
	return (fee + Package::calculateCost());
}

TwoDayPackage::~TwoDayPackage()
{
	fee = 0;
}
