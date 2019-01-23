#include <iostream>

/*
* Assignment 1 : Exercise 2.30
*
* Program functions as a BMI calculator which reads the user's weight in pounds
* and height in inchest then calculates and displays the user's body mass index.
*/

int main() {
	// declare variable
	float poundWeight{ 0 }, inchHeight{ 0 }, bmi{ 0 }; 

	// Get input from user (weight in lbs and height in inches)
	std::cout << "Input your weight in lbs: ";
	std::cin >> poundWeight;
	std::cout << "Input your height in inches: ";
	std::cin >> inchHeight;
	
	// caclulate BMI from user input
	bmi = (poundWeight * 703) / (inchHeight*inchHeight);

	// display user's BMI
	std::cout << "Your BMI is: " << bmi  << std::endl;
	
	// print info about the BMI standards.
	std::cout << "BMI VALUES\n"
		<< "Underweight: less than 18.5\n"
		<< "Normal:      between 18.5 and 24.9\n"
		<< "Overweight:  between 25 and 29.9\n"
		<< "Obese:       30 or greater\n";
	return system("pause"); // return system pause so console window doesnt close immediately
}