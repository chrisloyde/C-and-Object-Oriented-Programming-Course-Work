#include <iostream>
#include "InventoryRecord.h"

using namespace std;

InventoryRecord::InventoryRecord(int recordIn, const string& toolNameIn, int quantityIn, float costIn)
: record(recordIn), quantity(quantityIn), cost(costIn){
	setToolName(toolNameIn);
}

void InventoryRecord::setRecord(int x) {
	record = x;
}

int InventoryRecord::getRecord() const { return record;  }

void InventoryRecord::setToolName(const string& str) {
	size_t length{ str.size() }; // get size of string
	length = (length < 16 ? length : 15); // ensure our size is less then 16 characters
	str.copy(toolName, length); // copy to toolName
	toolName[length] = '\0'; // append null character.
}

string InventoryRecord::getToolName() const { return toolName; }

void InventoryRecord::setQuantity(int x) {
	quantity = x;
}

int InventoryRecord::getQuantity() const { return quantity; }

void InventoryRecord::setCost(float x) {
	cost = x;
}

float InventoryRecord::getCost() const { return cost; }

void InventoryRecord::listData() {
	cout << record << "		" << toolName << "		" << quantity << "		" << cost << endl;
}

InventoryRecord::~InventoryRecord()
{
}
