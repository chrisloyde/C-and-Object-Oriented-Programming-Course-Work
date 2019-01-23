/*
Exercise 11.9

Exercise 11.9 (Package Inheritance Hierarchy):
	Inheritance Structure:
		Package (base)
			+- Two Day Package
			+- Overnight Package
	Data:
		Package:
			- data members: name, address, city, state, ZIP (both sender and recipient)
				 Package Weight (in ounces), cost per ounce
			Constructor:
				Initializes all data members
			- Ensure weight and cost per ounce are positive.
			public double calculateCost() -> returns cost associated with shipping package (weight * cost per)
		Two Day Package:
			- inherit functionality of base-class Package.
			- data members: shipping flat fee
			Constructor:
				Receive a value to initialize flat fee data member.
			public double calculateCost() -> redefinied, (flat fee + (weight * cost per))
		Overnight Package:
			- inherit functionality of base-class Package.
			- data members: additional fee per ounce.
			Constructor:
				Receive a value to initialize fee data member.
			public double calculateCost() -> redefinied, ((add fee * weight) + (weight * cost per))

	Include test program tat creates objects of each type and tests member function calculateCost.

*/

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
	// Create Package objects
	Package filledPackage;
	Package negativeWeightPackage;
	TwoDayPackage twoDayPackage(5);
	OvernightPackage overnightPackage(0.25);

	// Assign informatino to one package, while this isn't used in testing I just provided it to show functionality
	filledPackage.setSenderInfo("James Smith", "1234 44 St.", "Tucson", "AZ", "12345");
	filledPackage.setRecipientInfo("Franklin Smith", "8822 N Tree Av.", "Dayton", "OH", "8765");
	filledPackage.setWeight(24.5);
	filledPackage.setCostPerOunce(0.50);

	// assign negative weights for negative weight testing
	negativeWeightPackage.setWeight(-16.0);
	negativeWeightPackage.setCostPerOunce(-0.25);

	twoDayPackage.setWeight(20);
	twoDayPackage.setCostPerOunce(1);

	overnightPackage.setWeight(8);
	overnightPackage.setCostPerOunce(0.5);

	// Testing
	printf("Testing Start\n");
	printf("\nTesting Package\n");

	printf("Testing CalculateCost\n");
	if (filledPackage.calculateCost() == 12.25) {
		printf("\tPassed\n");
	}
	else {
		cerr << "\tFailed to Calculate Cost: " << filledPackage.calculateCost() << " Should be 12.25" << endl;
	}

	printf("Testing Negative Weight and Cost\n");
	if (negativeWeightPackage.getWeight() == 0 && negativeWeightPackage.getCostPerOunce() == 0) {
		printf("\tPassed\n");
	}
	else {
		cerr << "\tFailed negative test: " << negativeWeightPackage.getWeight() << " & " << negativeWeightPackage.getCostPerOunce() << " Should not be negative." << endl;
	}

	printf("\nTesting Two Day Package\n");
	printf("Testing CalculateCost\n");
	if (twoDayPackage.calculateCost() == 25) {
		printf("\tPassed\n");
	}
	else {
		cerr << "\tFailed to Calculate Cost: " << twoDayPackage.calculateCost() << " Should be 25.00" << endl;
	}

	printf("\nTesting Overnight Package\n");
	printf("Testing CalculateCost\n");
	if (overnightPackage.calculateCost() == 6) {
		printf("\tPassed\n");
	}
	else {
		cerr << "\tFailed to Calculate Cost: " << overnightPackage.calculateCost() << " Should be 6.00" << endl;
	}

	getchar();
	return 0;
}
