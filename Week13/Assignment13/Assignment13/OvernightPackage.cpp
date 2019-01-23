#include "OvernightPackage.h"



OvernightPackage::OvernightPackage(double additionalFeePerOunce)
{
	// ensure fee is positive
	if (additionalFeePerOunce < 0) {
		fee = 0;
	}
	else {
		fee = additionalFeePerOunce;
	}
}

double OvernightPackage::calculateCost() {
	// calculated using ((additional fee * ounces) + (costPerOunce * ounces))
	return ((fee*getWeight()) +  Package::calculateCost());
}

OvernightPackage::~OvernightPackage()
{
	fee = 0;
}
