#pragma once
#include "Package.h"
class OvernightPackage :
	public Package
{
public:
	OvernightPackage(double fee);
	double calculateCost() override;
	~OvernightPackage();
private:
	double fee;
};

