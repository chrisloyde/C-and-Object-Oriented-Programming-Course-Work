#include <iostream>

class InventoryRecord
{
public:
	int record;	
	char toolName[16];
	int quantity;
	float cost;

	InventoryRecord(int = 0, const std::string& = "", int = 0, float = 0.0f); // default
	
	// getters and setters for each public variable.
	void setRecord(int);
	int getRecord() const;
	
	void setToolName(const std::string&);
	std::string getToolName() const;

	void setQuantity(int);
	int getQuantity() const;

	void setCost(float);
	float getCost() const;

	void listData();


	~InventoryRecord();
};

