#include <iostream>
#include <fstream>

#include "InventoryRecord.h" // include InventoryRecord object

/*
Assignment 3: Exercise 13.17 & 14.11

Exercise 13.17: Printing a Table of ASCII Values
Uses a for statement to print a table of ASCII value for the characters in the ASCII
character set from 33 to 126 (inclusive). Prints a decimal value, octal value, hexadecimal value,
and character value for each charater.
Uses stream manipulators dec, oct, and hex to print integer values.

Exercise 14.11: Hardware Inventory
Initialized the random-access file "hardware.dat" to 100 empty records, lets you
input the data concerning each tool, enables you to list all your tools,
delete a record for a tool that you no longer have and update any
information in the file. 
The tool identification number should be the record number.
*/

using namespace std;

int exercise13_17();
int exercise14_11();
void listTools(fstream&);
void addTool(fstream&);
void modifyRecord(fstream&);
void deleteRecord(fstream&);
int retrieveRecord(const char* const);
void quickAdd(fstream&, InventoryRecord, int);
void quickDelete(fstream&, int);

int main() {
	int in{ 0 };

	// do while loop to keep prompting until correct input.
	do {
		cout << "Enter exercise number (13 for 13.17 or 14 for 14.11): ";
		cin >> in;
	} while(in != 13 && in != 14);

	if (in == 13) {
		exercise13_17();
	}
	if (in == 14) {
		exercise14_11();
	}
	return 0;
}

int exercise13_17() {
	// print headers
	cout << "Decimal		Octal		Hexadecimal	Character" << endl;
	// loop from 33 to 126, uses unsigned int because i is never negative
	for (unsigned int i = 33; i < 127; i++) {
		cout << dec << i; // print decimal.
		cout << "		" << oct << i; // prints octal.
		cout << "		" << hex << i; // prints hexadecimal.
		cout << "		" << (char)i << endl; // prints character
	}
	return system("pause");
}

int exercise14_11() {
	ofstream createFile;
	createFile.open("hardware.dat"); // create a hardware.dat file if one does not already exist.
	createFile.close(); // immediately close since this code's only purpose is to add a file if there
						// isn't one.

	fstream file{"hardware.dat", ios::in | ios::out | ios::binary}; // try to open file.
	// Craete file since one cannot be opened.
	if (!file.is_open()) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	InventoryRecord record; // default constructor 0s all data

	// add 100 empty records to file.
	for (int i{ 0 }; i < 100; i++) {
		file.write(reinterpret_cast<const char*>(&record), sizeof(InventoryRecord));
	}

	int cmdIn{ -2 };
	while (cmdIn != -1) {
		cout << "Enter 0 to list records\n" 
			<< "1 to add a new record\n"
			<< "2 to modify an existing record\n"
			<< "3 to delete an existing record\n"
			<<"-1 to Exit: ";
		cin >> cmdIn;
		switch (cmdIn) {
		case 0: // list
			listTools(file);
			break;
		case 1: // add
			addTool(file);
			break;
		case 2: // modify
			modifyRecord(file);
			break;
		case 3: // delete
			deleteRecord(file);
			break;
		case -1: // exit
			cmdIn = -1;
			break;
		default: // incorrect choice
			cerr << cmdIn << " is not an option.";
			break;
		}

		file.clear(); // reset end of file indicator at the end of each loop iteration.
	}
	return system("pause");
}

void listTools(fstream& file) {
	// print headers
	cout << "Record #	Tool Name	Quantity	Cost" << endl;
	//print contents of file.
	file.seekg(0); // set file position pointer to beginning of file.
	InventoryRecord record;
	file.read(reinterpret_cast<char*>(&record), sizeof(InventoryRecord)); // read first record

	// loop until at the end of file.
	while (!file.eof()) {
		if (record.record != 0) { // ensure its not an empty record.
			record.listData(); // print out data
		}
		file.read(reinterpret_cast<char*>(&record), sizeof(InventoryRecord)); // read next record
	}

}

void addTool(fstream& file) {
	int recordNumber{ retrieveRecord("Enter new account number: ") };

	// move file pointer to correct position
	// which is the record number location multiplied by the size of an InventoryRecord.
	file.seekg((recordNumber - 1) * sizeof(InventoryRecord)); // get pointer
	
	// read record from file.
	InventoryRecord newRecord;
	file.read(reinterpret_cast<char*>(&newRecord), sizeof(InventoryRecord));

	// check if record is empty, if it is empty then we can create a new one
	// if record is not empty then we print an error.
	if (newRecord.getRecord() == 0) { // empty record
		char toolName[15];
		int quantity;
		float price;

		cout << "Enter Toolname, quantity, and price: \n";
		cout << "Toolname: "; cin >> toolName;
		cout << "Quantity: "; cin >> quantity;
		cout << "Price: "; cin >> price;

		// add inputted values to record object.
		newRecord.setRecord(recordNumber);
		newRecord.setToolName(toolName);
		newRecord.setQuantity(quantity);
		newRecord.setCost(price);

		// move file position pointer to the correct spot.
		file.seekp((recordNumber - 1) * sizeof(InventoryRecord)); // put pointer

		file.write(reinterpret_cast<const char*>(&newRecord), sizeof InventoryRecord);
	}
	else {// existing record
		cerr << "Record number " << recordNumber << " already exists." << endl;
	}
}

void deleteRecord(fstream& file) {
	int recordNumber{ retrieveRecord("Enter account number to delete: ") };

	// get record location
	file.seekg((recordNumber-1)*sizeof(InventoryRecord));
	InventoryRecord deleteRecord;
	// read data from record location and store in deleteRecord
	file.read(reinterpret_cast<char*>(&deleteRecord), sizeof(InventoryRecord));

	if (deleteRecord.getRecord() != 0) { // record is not empty
		InventoryRecord blankRecord; // new blank record
		file.seekp((recordNumber - 1) * sizeof(InventoryRecord)); // move pointer to record location
		// write blank record to file location.
		file.write(reinterpret_cast<const char*>(&blankRecord), sizeof(InventoryRecord)); 
		cout << "Inventory record #" << recordNumber << " was succesfully deleted." << endl;

	}
	else { // record is empty
		cerr << "Inventory record #" << recordNumber << " is already empty." << endl;
	}
}

void modifyRecord(fstream& file) {
	int recordNumber = { retrieveRecord("Enter record # to update: ") };

	// get record location from record number
	file.seekg((recordNumber - 1) * sizeof(InventoryRecord));
	// read record in that location
	InventoryRecord record;
	file.read(reinterpret_cast<char *>(&record), sizeof(InventoryRecord));

	// get modifications from user.
	if (record.getRecord() != 0) {
		int newNum{ 0 }, newQuantity{ 0 };
		char newToolName[15]{ "" };
		float newPrice{ 0.0 };


		cout << "Record #	Tool Name	Quantity	Cost" << endl;
		record.listData(); // display record information.

		int cmdIn{ -1 };
		cout << "Any information can be updated\n"
			<< "0 to change record number.\n"
			<< "1 to change tool name.\n"
			<< "2 to change quantity.\n"
			<< "3 to change cost.\n";
		cin >> cmdIn;
		switch (cmdIn) {
		case 0:
			newNum = retrieveRecord("Enter new record number: ") ;
			// changing record number means we need to add this record
			// at the new location, and delete this record from its current location.
			quickAdd(file, record, newNum);
			quickDelete(file, recordNumber);

			// update the record number we are updating.
			recordNumber = newNum;
			// update position of pointer.
			file.seekg((recordNumber - 1) * sizeof(InventoryRecord));
			// re-read record in.
			file.read(reinterpret_cast<char *>(&record), sizeof(InventoryRecord));
			break;
		case 1:
			cout << "Enter new toolname: "; cin >> newToolName;
			record.setToolName(newToolName);
			// move file position pointer to the correct spot, and write record in.
			file.seekp((recordNumber - 1) * sizeof(InventoryRecord)); 

			file.write(reinterpret_cast<const char*>(&record), sizeof InventoryRecord);
			break;
		case 2:
			cout << "Enter new quantity: "; cin >> newQuantity;

			record.setQuantity(newQuantity);
			// move file position pointer to the correct spot, and write record in.
			file.seekp((recordNumber - 1) * sizeof(InventoryRecord)); 

			file.write(reinterpret_cast<const char*>(&record), sizeof InventoryRecord);
			break;
		case 3:
			cout << "Enter new price: "; cin >> newPrice;
			record.setCost(newPrice);
			// move file position pointer to the correct spot, and write record in.
			file.seekp((recordNumber - 1) * sizeof(InventoryRecord)); 

			file.write(reinterpret_cast<const char*>(&record), sizeof InventoryRecord);
			break;
		default: break;
		}
				
	}
	else {
		cerr << "Account #" << recordNumber << " doesn't exist." << endl;
	}
}

int retrieveRecord(const char* const prompt) {
	int recordNumber;
	// use a do while loop to keep prompting until correct response is given.
	do {
		cout << prompt << "(1-100): ";
		cin >> recordNumber;
	} while (recordNumber < 1 || recordNumber > 100);

	return recordNumber;
}

void quickAdd(fstream& file, InventoryRecord record, int newNum) {
	file.seekg((newNum-1)*sizeof(InventoryRecord)); // move pointer to new location
	InventoryRecord chkRecord;
	file.read(reinterpret_cast<char*>(&chkRecord), sizeof(InventoryRecord));
	if (chkRecord.record == 0) {
		// new record location is empty, so add record.
		record.setRecord(newNum);
		file.seekp((newNum - 1) * sizeof(InventoryRecord)); // put pointer

		file.write(reinterpret_cast<const char*>(&record), sizeof InventoryRecord);
	}
	else {
		cerr << "A record already exists at #" << newNum << endl;
	}
}

void quickDelete(fstream& file, int recordNum) {
	// get record location
	file.seekg((recordNum - 1) * sizeof(InventoryRecord));
	InventoryRecord deleteRecord;
	// read data from record location and store in deleteRecord
	file.read(reinterpret_cast<char*>(&deleteRecord), sizeof(InventoryRecord));

	if (deleteRecord.getRecord() != 0) { // record is not empty
		InventoryRecord blankRecord; // new blank record
		file.seekp((recordNum - 1) * sizeof(InventoryRecord)); // move pointer to record location
																  // write blank record to file location.
		file.write(reinterpret_cast<const char*>(&blankRecord), sizeof(InventoryRecord));
		cout << "Inventory record #" << recordNum << " was succesfully deleted." << endl;

	}
	else { // record is empty
		cerr << "Inventory record #" << recordNum << " is already empty." << endl;
	}
}