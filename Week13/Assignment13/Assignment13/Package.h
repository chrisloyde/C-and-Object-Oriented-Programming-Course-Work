#pragma once
#include <string>
#include <iostream>

using namespace std;
class Package
{
// MACROS that define storage location
#define NAME	0
#define ADDRESS 1
#define CITY	2
#define STATE	3
#define ZIP		4

public:
	Package();
	string* setSenderInfo(string senderName, string senderAddress, string senderCity, string senderState, string senderZip);
	string* setRecipientInfo(string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZip);
	void setWeight(double weightInOunces);
	void setCostPerOunce(double costPerOunce);
	double getWeight();
	double getCostPerOunce();
	virtual double calculateCost();
	virtual void displayPackage();
	const char* getSenderName();
	const char* getSenderAddress();
	const char* getSenderCity();
	const char* getSenderState();
	const char* getSenderZip();
	const char* getRecipientName();
	const char* getRecipientAddress();
	const char* getRecipientCity();
	const char* getRecipientState();
	const char* getRecipientZip();
	~Package();
protected:
	string * sName, *sAddress, *sCity, *sState, *sZip; // sender data members
	string *rName, *rAddress, *rCity, *rState, *rZip; // recipient data members
private:
	string senderInfo[5]; // storage for sender data members
	string recipientInfo[5]; // storage for recipient data members
	double weight; // in ounces
	double cost; // cost per ounces

};

