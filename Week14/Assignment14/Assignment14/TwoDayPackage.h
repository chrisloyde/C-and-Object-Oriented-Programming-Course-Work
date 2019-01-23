#pragma once
#include "Package.h"
class TwoDayPackage :
	public Package
{
public:
	TwoDayPackage(double flatFee);
	double calculateCost() override;
	~TwoDayPackage();
private:
	double fee;
};

