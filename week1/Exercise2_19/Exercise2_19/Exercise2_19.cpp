#include <iostream>

/*
* Assignment 1 : Exercise 2.19
*
* Program accepts 3 integers from input then prints the
* sum, average, product, smallest, and largest integer.
*/

// defining functions
int checkLargest(int a, int b);
int checkSmallest(int a, int b);

int main() {
	// defining variables
	int x{ 0 }, y{ 0 }, z{ 0 }, smallest{ 0 }, largest{ 0 };
	std::cout << "Input three different integers: \n"; 

	// get 3 inputs from user
	std::cin >> x; // get x from user
	smallest = x; largest = x; // first input will always be both smallest and largest
	std::cin >> y; // get y from user
	largest = checkLargest(y, largest); // check new input against current largest
	smallest = checkSmallest(y, smallest); // check new input againts current smallest
	// do same procedure that we did for y, except for new input z.
	std::cin >> z;
	largest = checkLargest(z, largest);
	smallest = checkSmallest(z, smallest);

	//print out all results
	std::cout << "Sum is " << x + y + z << std::endl;
	std::cout << "Average is " << (x + y + z) / 3 << std::endl;
	std::cout << "Product is " << x * y*z << std::endl;
	std::cout << "Smallest is " << smallest << std::endl;
	std::cout << "Largest is " << largest << std::endl;

	return system("pause"); // calling a system pause so the console window doesnt instantly close.
}

// accepts to integers and returns the largest of the two.
int checkLargest(int a, int b) {
	if (a > b) {
		return a;
	} else{
		return b;
	}
}

// accepts to integers and returns the smallest of the two.
int checkSmallest(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}