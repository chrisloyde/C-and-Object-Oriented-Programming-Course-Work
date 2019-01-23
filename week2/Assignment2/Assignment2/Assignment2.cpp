#include <iostream>

/*
* Assignment 2 : Exercise 4.14 & 4.15
*
* Exercise 4.14: (Credit Limits) Program will determine whether a department store customer
* has exceeded the credit limit on a charge account.
* Exercise 4.15: (Sales-Commission Calculator) Program accepts a sales amount (in dollars)
* from user and determines comission that salesperson should receive.
*/

// declaring functions.
int exercise4_14();
int exercise4_15();

int main() {
	int input{ 0 };
	// get input from user to determine which exercise to run (4.14 or 4.15)
	std::cout << "Enter exercise number to run (14 or 15): ";
	std::cin >> input;
	std::cout << std::endl;

	// if input is 14 run exercise 4.14
	if (input == 14) {
		exercise4_14();
	}
	// if input is 15 run exercise 4.15
	else if (input == 15) {
		exercise4_15();
	}
	// if input is invalid print an error statement and call main again.
	else {
		std::cout << "Invalid exervise number: " << input << std::endl;
		main();
	}
	return 0; // no errors so return 0
}

int exercise4_14() {
	// declaring variables
	int accountNum{ 0 };
	float beginningBalance{ 0 }, totalCharges{ 0 },
		totalCredits{ 0 }, creditLimit{ 0 }, newBalance{ 0 };

	// loop so multiple accounts can be looked at.
	while (true) {
		std::cout << "Enter account number (or -1 to quit): "; std::cin >> accountNum;
		// break on quit code.
		if (accountNum == -1) {
			break;
		}

		// input facts about customer.
		std::cout << "Enter beginning balance: "; std::cin >> beginningBalance;
		std::cout << "Enter total charges: "; std::cin >> totalCharges;
		std::cout << "Enter total credits: "; std::cin >> totalCredits;
		std::cout << "Enter credit limit: "; std::cin >> creditLimit;
		std::cout << std::endl;

		// calculate new balance based off customer facts.
		newBalance = (beginningBalance + (totalCharges - totalCredits));

		// if customer credit limit is exceeded print information for customer.
		if (newBalance > creditLimit) {
			std::cout << "New balance is " << newBalance << std::endl;
			std::cout << "Account: " << accountNum << std::endl;
			std::cout << "Credit limit: " << creditLimit << std::endl;
			std::cout << "Balance: " << newBalance << std::endl;
			std::cout << "Credit Limit Exceeded." << std::endl;
		}
		// if customer credit limit is not exceeded then just the new balance is printed.
		else {
			std::cout << "New balance is " << newBalance << std::endl;
		}

	}

	return 0; // no errors so return 0
}

int exercise4_15() {
	float sales{ 0 };
	// loop so multiple sales figures can be looked at.
	while (true) {
		std::cout << "Enter sales in dollars (-1 to end): "; std::cin >> sales;
		// break on quit code
		if (sales == -1) {
			break;
		}

		//print salary using formula 200 + (9% * total sales)
		std::cout << "Salary is: $" << 200.00 + (.09*sales) << std::endl;
	}

	return 0; // no errors so return 0;
}