#include "Package.h"

Package::Package()
{
	// assign all pointers to their respective storage
	sName		= &senderInfo[NAME];
	sAddress	= &senderInfo[ADDRESS];
	sCity		= &senderInfo[CITY];
	sState		= &senderInfo[STATE];
	sZip		= &senderInfo[ZIP];

	rName		= &recipientInfo[NAME];
	rAddress	= &recipientInfo[ADDRESS];
	rCity		= &recipientInfo[CITY];
	rState		= &recipientInfo[STATE];
	rZip		= &recipientInfo[ZIP];

	// set all info to undefined.
	setSenderInfo("undefined", "undefined", "undefined", "undefined", "undefined");
	setRecipientInfo("undefined", "undefined", "undefined", "undefined", "undefined");
	// set numerical data members to 0
	setWeight(0.0);
	setCostPerOunce(0.0);

}

string * Package::setSenderInfo(string sN, string sA, string sC, string sS, string sZ) {
	senderInfo[NAME]	= sN;
	senderInfo[ADDRESS] = sA;
	senderInfo[CITY]	= sC;
	senderInfo[STATE]	= sS;
	senderInfo[ZIP]		= sZ;

	return senderInfo;
}

string * Package::setRecipientInfo(string rN, string rA, string rC, string rS, string rZ) {
	recipientInfo[NAME]		= rN;
	recipientInfo[ADDRESS]	= rA;
	recipientInfo[CITY]		= rC;
	recipientInfo[STATE]	= rS;
	recipientInfo[ZIP]		= rZ;

	return recipientInfo;
}

void Package::setWeight(double d) {
	// check if weight is a positive number, if not set to 0
	if (d < 0) {
		weight = 0.0;
	}
	else {
		weight = d;
	}
}

void Package::setCostPerOunce(double d) {
	// check if costPerOunce is a positive number, if not set to 0
	if (d < 0) {
		cost = 0.0;
	} 
	else {
		cost = d;
	}
}

double Package::getWeight() {
	return weight;
}

double Package::getCostPerOunce() {
	return cost;
}

double Package::calculateCost() {
	// cost of package is determined by equation (ounces * cost)
	return (weight * cost);
}

void Package::displayPackage() {
	printf("<Package>\n");
	printf("Sender:\t\t %s %s %s %s %s\n", 
		senderInfo[NAME].c_str(), senderInfo[ADDRESS].c_str(), senderInfo[CITY].c_str(), senderInfo[STATE].c_str(), senderInfo[ZIP].c_str());
	printf("Recipient:\t %s %s %s %s %s\n", 
		recipientInfo[NAME].c_str(), recipientInfo[ADDRESS].c_str(), recipientInfo[CITY].c_str(), recipientInfo[STATE].c_str(), recipientInfo[ZIP].c_str());
	printf("%.2lf Ounces\n", weight);
	printf("$%.2lf Per Ounce\n", cost);
	printf("Package Price: $%.2lf\n", calculateCost());
	printf("<End Package>\n");
}

const char* Package::getSenderName() {
	return senderInfo[NAME].c_str();
}

const char* Package::getSenderAddress() {
	return senderInfo[ADDRESS].c_str();
}

const char* Package::getSenderCity() {
	return senderInfo[CITY].c_str();
}

const char* Package::getSenderState() {
	return senderInfo[STATE].c_str();
}

const char* Package::getSenderZip() {
	return senderInfo[ZIP].c_str();
}

const char* Package::getRecipientName() {
	return recipientInfo[NAME].c_str();
}

const char* Package::getRecipientAddress() {
	return recipientInfo[ADDRESS].c_str();
}

const char* Package::getRecipientCity() {
	return recipientInfo[CITY].c_str();
}

const char* Package::getRecipientState() {
	return recipientInfo[STATE].c_str();
}

const char* Package::getRecipientZip() {
	return recipientInfo[ZIP].c_str();
}

Package::~Package()
{
	// all pointers set to null to avoid dangling pointers
	sName		= nullptr;
	sAddress	= nullptr;
	sCity		= nullptr;
	sState		= nullptr;
	sZip		= nullptr;

	rName		= nullptr;
	rAddress	= nullptr;
	rCity		= nullptr;
	rState		= nullptr;
	rZip		= nullptr;

	// info erased
	senderInfo[NAME]	= "";
	senderInfo[ADDRESS] = "";
	senderInfo[CITY]	= "";
	senderInfo[STATE]	= "";
	senderInfo[ZIP]		= "";

	recipientInfo[NAME]		= "";
	recipientInfo[ADDRESS]	= "";
	recipientInfo[CITY]		= "";
	recipientInfo[STATE]	= "";
	recipientInfo[ZIP]		= "";

	// numerical data member set to 0
	weight	= 0.0;
	cost	= 0.0;
}
