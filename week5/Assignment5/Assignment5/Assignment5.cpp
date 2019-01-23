#include <iostream>
/*
Assignment 5: Exercise 5.11, 5.12, 5.17

Exercise 5.11: (Find the smallest value) 
	Finds the smallest of several integers, assumes the first value read is the number of inputs from user.
Exercise 5.12: (Calculating the Product of Odd Integers) 
	Calculates the product of the odd integers from 1 to 15.
Exercise 5.17: (Calculating Sales)
	Product 1: $2.98	Product 4: $4.49
	Product 2: $4.50	Product 5: $6.87
	Product 3: $9.98
	Reads a series of pairs of numbers as follows (product number, quantity sold). Using a switch statement to determine the retail price for each
	product, calculate and display the total retail value of all products sold. Use sentinel-controlled loop.
*/

int Exercise5_11();
int Exercise5_12();
int Exercise5_17();

int main() {
	int in{ 0 };
	do {
		printf("Enter 11 for 5.11\nEnter 12 for 5.12\nEnter 17 for 5.17\nEnter -1 for quit\n");
		scanf("%d", &in);
		switch (in) {
		case -1: break;
		default: printf("Invalid Exercise number.\n"); break;
		case 11: Exercise5_11(); break;
		case 12: Exercise5_12(); break;
		case 17: Exercise5_17(); break;
		}
	} while (in != -1);
	return 0;
}

int Exercise5_11() {
	printf("Running Execise 5.11\n");
	int tot{ 0 }, min{ 0 }, in{ 0 };
	printf("Enter number of inputs for \"Find Smallest Value\": ");
	scanf("%d", &tot);

	// loop to get input from user corresponding to amount of inputs they specified.
	printf("Input %d integers\n", tot);
	for (int i = 0; i < tot; i++) {
		scanf("%d", &in);
		// on first iteration set min to the first number inputted.
		if (i == 0) {
			min = in;
		}
		// find minimum
		if (in < min) {
			min = in;
		}
	}
	printf("Minimum value determined from input is %d\n", min);
	return system("pause");
}

int Exercise5_12() {
	printf("Running Execise 5.12\n");
	int prod{ 1 };
	// loop from 1 to 15
	// increment by 2, starting at 1.
	for (int i = 1; i < 16; i+=2) {
		prod = prod * i;
	}
	printf("Product of odd numbers from 1 to 15 is %d\n", prod);
	return system("pause");
}

int Exercise5_17() {
	printf("Running Exercise 5.17\n");
	int inA{ 0 }, inB{ 0 }; // product number, quantity sold
	float rP{ 0 }, tV{ 0 }; // retail price, total Value

	while (inA != -1 || inB != -1) {
		printf("Enter number pair\n\ta.product number(1-5)\n\tb.quantity sold\nEnter -1 (either paired or on its own) to exit.\n");
		scanf("%d%d", &inA, &inB);
		rP = 0; // reset retail price every interation
		switch (inA) {
		case -1: rP = 0; break; // quit case
		case 1: rP = inB * 2.98F; break;
		case 2: rP = inB * 4.50F;  break;
		case 3: rP = inB * 9.98F; break;
		case 4: rP = inB * 4.49F; break;
		case 5: rP = inB * 6.87F; break;
		default: 
			rP = 0;
			printf("Invalid Product number, must be 1-5.\n");
			break;
		}
		tV += rP; // add calculated retail price to total value
	}
	printf("Total Value is: $%.2f\n", tV);
	return system("pause");
}