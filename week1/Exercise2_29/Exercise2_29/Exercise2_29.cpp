#include <iostream>
/*
* Assignment 1 : Exercise 2.29
*
* Calculates surface area and volume of cubes with face lengths 0 to 4 cm.
*/

// defining functions
int cSAC(int x); // calculates surface area of a cube.
int cVC(int x); // calculates volume of a cube.

int main() {
	// Print out the face length being calculated, surface area, and volume of a cube
	// in a neat formatted way.
	std::cout << "Face length		Surface area		Volume\n"
			  << "of cube (cm)		of cube (cm^2)		of cube(cm^3)\n"
			  << "0			" << cSAC(0) << "			" << cVC(0) << "\n"
			  << "1			" << cSAC(1) << "			" << cVC(1) << "\n"
			  << "2			" << cSAC(2) << "			" << cVC(2) << "\n"
			  << "3			" << cSAC(3) << "			" << cVC(3) << "\n"
			  << "4			" << cSAC(4) << "			" << cVC(4) << "\n";
	
	return system("pause"); // return a system pause so console window doesn't immediately close.
}

int cSAC(int x) {
	return (6 * (x * x)); // returns surface area of cube with x length side.
}

int cVC(int x) {
	return (x*x*x); // returns volume of cube with x length side.
}