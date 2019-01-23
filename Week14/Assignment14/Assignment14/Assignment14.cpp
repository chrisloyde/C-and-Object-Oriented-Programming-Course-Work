/*
Exercise 12.12 pg 574 (Package Inheritance Hierarchy):
	Uses Package Hierarchy from Assignment 13
	Program displays address information and calculates the shipping costs for several Packages.
	Data:
		Vector containing Package pointers to TwoDayPackage(s) and OvernightPackage(s)
		Vector should be looped through to process Packages polymorphically
	Function:
		Use get functions to obtain address information of the sender and the recipient, then print the two addresses as they would appear on mailing labels.
		Call each Package's calculateCost function and print the result.
		Keep track of the total shipping cost for all Packages in the vector, and display the total when the loop terminates.
*/

#include <cstdio>
#include <vector>
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

vector<Package *> packages;

void loadPackages();
void printPackages();
void destroyPackages();

int main() {
	loadPackages(); // load packages into packages vector
	printPackages(); // loop through packages and display each one, while calculating shipping costs
	destroyPackages(); // free memory created by packages

	getchar();
	return 0;
}

void loadPackages() {
	// Two Day Package Creation
	TwoDayPackage *tDPackage1 = new TwoDayPackage(7.00); // $7.00 flat fee
	TwoDayPackage *tDPackage2 = new TwoDayPackage(5.78); // $5.78 flat fee

	tDPackage1->setCostPerOunce(0.1); // $0.10 fee per ounce
	tDPackage2->setCostPerOunce(0.25); // $0.25 fee per ounce

	tDPackage1->setWeight(16); // 1lb package
	tDPackage2->setWeight(64); // 4lb package

	tDPackage1->setSenderInfo("Jack Land", "4058 Roosevelt Street", "San Francisco", "CA", "94115");
	tDPackage1->setRecipientInfo("Bob Smith", "3052 Meadowview Drive", "Roanoke", "VA", "24011");

	tDPackage2->setSenderInfo("Alfred Stevens", "1058 Pinnickinnick Street", "New Brunswick", "NJ", "08901");
	tDPackage2->setRecipientInfo("Sheila Henry", "4074 Spadafore Drive", "Hooversville", "PA", "15936");

	// Overnight Package Creation
	OvernightPackage *oPackage1 = new OvernightPackage(0.45); // additional 45 cent fee per ounce
	OvernightPackage *oPackage2 = new OvernightPackage(0.62); // additional 62 cent fee per ounce

	oPackage1->setCostPerOunce(0.15); // 15 cent fee per ounce
	oPackage2->setCostPerOunce(0.30); // 30 cent fee per ounce

	oPackage1->setWeight(160); // 10lb package 
	oPackage2->setWeight(58); // 3.625lb package

	oPackage1->setSenderInfo("Erin Greer", "2288 Tator Patch Road", "Chicago", "IL", "60610");
	oPackage1->setRecipientInfo("Gerard Knight", "529 Rosewood Court", "New Ulm", "MN", "56073");

	oPackage2->setSenderInfo("Regina Strickland", "1788 Haul Road", "San Francisco", "CA", "94103");
	oPackage2->setRecipientInfo("Lloyd Hopkins", "3216 Byrd Lane", "La Mesa", "NM", "8804");


	// Add Packages to vector
	packages.push_back(tDPackage1);
	packages.push_back(tDPackage2);
	packages.push_back(oPackage1);
	packages.push_back(oPackage2);
}

void printPackages() {
	double totalShippingCost = 0.0;
	for (auto package : packages) {
		printf("%-32s %-32s\n", package->getSenderName(), package->getRecipientName()); // print names
		printf("%-32s %-32s\n", package->getSenderAddress(), package->getRecipientAddress()); // print addresses
		printf("%-16s %-2s %-13s", package->getSenderCity(), package->getSenderState(), package->getSenderZip()); // Sender state, city, and zip info
		printf("%-16s %-2s %-13s\n", package->getRecipientCity(), package->getRecipientState(), package->getRecipientZip()); // Recipient state, city, and zip info
		printf("Shipping Cost: $%.2lf\n", package->calculateCost()); // display cost
		totalShippingCost += package->calculateCost(); // add this packages cost to the total
		printf("\n");
	}

	printf("Total From Shipping Costs: $%.2lf\n", totalShippingCost); // print total costs
}

void destroyPackages() {
	// irterate through packages vector and destroy created objects.
	for (std::vector<Package *>::iterator i = packages.begin(); i != packages.end(); ++i) {
		delete *i;
	}
	packages.clear();
}