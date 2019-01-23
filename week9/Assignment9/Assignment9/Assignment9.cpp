/*
Exercise 7.28 (Palindromes):
	Palindrome: string that's spelled the same way forward and backward.
	Recursive function testPalindrome that returns true if a string is a palindrome.
Exercise 7.32 pg 335-336 (Find The Minimum Value in an array):
	Recursive function recursiveMinimum that accepts integer array, starting subscript, and ending subscript 
	and returns the smallest element of the array.Function should stop processing and return when starting subscript
	equals ending subscript.
	
Exericsie 17.26 pg. 782 (Catching All Exceptions):
	Program that demonstrates several exception types being caught with catch(...) exception handler.
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>

using namespace std;

// removes everything except for letters from a string, also converts all letters to lower case.
string cleanString(string str);
// recursively gets the palindrome of a string.
bool palindrome(string str);
// finds smallest integer in array recursively
int recursiveMinimum(int *arr, int startingSubscript, int endingSubscript);
void exceptionHandler();

// struct which contains functions that can throw exceptions
struct exceptionGenerator : public exception {
	int divide(int numerator, int denominator) {
		if (denominator == 0) {
			throw "Exception: Division by Zero\n";
		}

		return numerator/denominator;
	}
	int getElementFromArray(int *arr, int subscript, int size) {
		if (subscript > (size-1) || subscript < 0) {
			throw "Exception: Array Out of Bounds\n";
		}
		
		return arr[subscript];
	}
	int* setElementToArray(int *arr, int subscript, int value, int size) {
		if (subscript > (size - 1) || subscript < 0) {
			throw "Exception: Array Out of Bounds\n";
		}
		arr[subscript] = value;
		return arr;
	}

	void throwBadAlloc() {
		throw bad_alloc();
	}

	void throwOverflowError() {
		throw overflow_error("Overflow Error");
	}
};

int main() {

	// string that can be easily modified to test other palindromes.
	string customPalindrome("Fillif"); 

	// custom array that can be easily modified to test recursiveMinimum.
	int customMinimum[4]{50,20,10,80};
	int customStartSubscript = 0;
	int customEndSubscript = 3;

	printf("Palindromes: (1 for True, 0 for False)\n");
	printf("Is \"%s\" a Palindrome?  \t%d\n", "cook", palindrome(string("cook")));
	printf("Is \"%s\" a Palindrome?  \t%d\n", "racecar", palindrome(string("racecar")));
	printf("Is \"%s\" a Palindrome?  \t%d\n", "Hannah", palindrome(string("Hannah")));
	printf("Is \"%s\" a Palindrome?  \t%d\n", "Orange", palindrome(string("Orange")));
	printf("Is \"%s\" a Palindrome?  \t%d\n", "Rotavator", palindrome(string("Rotavator")));
	printf("Is \"%s\" a Palindrome?  \t%d\n", customPalindrome.c_str(), palindrome(customPalindrome));

	printf("\nPress Enter for recusiveMinimum"); getchar();

	printf("Minimum of {0,1,2,3,4,5} is %d\n", recursiveMinimum(new int[6]{ 0,1,2,3,4,5 }, 0, 5));
	printf("Minimum of {100,-80,8,32,410,5} is %d\n", recursiveMinimum(new int[6]{ 100,-80,8,32,410,5 }, 0, 5));
	printf("Minimum of {900,899} is %d\n", recursiveMinimum(new int[2]{ 900,899 }, 0, 1));
	printf("Minimum of CUSTOM ARRAY is %d\n", recursiveMinimum(customMinimum, customStartSubscript, customEndSubscript));


	printf("\nPress Enter for exceptionHandler\n"); getchar();

	exceptionHandler();

	printf("\nPress Enter to Exit\n"); getchar();
	return 0;
}

bool palindrome(string str) {
	// clean up the string, while this doesn't need to be done every call, if there isn't non-letters
	// in the string already the time it takes to call this is negligible.
	str = cleanString(str);

	// base case, if string is of length 1 or 0, it must be a palindrome.
	if (str.size() <= 1) {
		return true;
	}

	// compare character at the end of the string to the character at the start of the string
	if (str.at(str.size() - 1) == str.at(0)) {
		str.erase(0,1); // erase character at start
		str.erase(str.size() - 1); // erase character at end
		if (palindrome(str)) { // recursively call palindrome
			return true; // if the recursive call to palindrome is true then return true
		}
	}
	else {
		return false; // if the characters at the start and end of the string are not equal then return false.
	}

	// really should never get to this point but if it did then the string must not be a palindrome.
	return false;

}

string cleanString(string str) {
	// allocate size for array, 
	//	setting size equal to string to ensure we have enough memory.
	int *arr = (int *)malloc(str.size() * sizeof(int *));
	int inc = 0; // declaring a counter which will be important when removing white spaces and non-letters
	
	// loop to find anything that isnt a letter
	for (int i = 0; i < str.size(); i++) {
		arr[i] = -1; // intialize every element in integer array to 01
		str[i] = tolower(str[i]); // set this character to lowercase
		// if the character is not a letter, give its position to integer array
		if ((int)str[i] < 97 || (int)str[i] > 122) {
			arr[i] = i;
		}
	}

	// loop to remove characters that aren't letters
	for (int i = 0; i < str.size(); i++) {
		// if element in integer array is not the default -1
		if (arr[i] != -1) {
			// erase from string at position determined by what is and isn't a letter.
			// Subtract inc since every time we remove an element from the string, the latter half moves back 1 space
			//	e.g Word: Palindrome, if I remove the l at position 2 then the word becomes Paindrome, meaing the i
			//				and everything after shifted back 1 spaces which we need to compensate for.
			str.erase(arr[i] - inc, 1);
			inc++;
		}
	}
	printf("");
	
	delete[] arr; // free up space to avoid memory leak

	// returning a string instead of modifying parameter since this function will essentiall destroy the original string. 
	return str;
}

int recursiveMinimum(int *arr, int s, int e) {
	// base case, if starting subscript is equal to ending subscript then we are at the end of the array.
	if (s == e) {
		return arr[s];
	}

	// if integer at arr[starting subscript] is less then the next integer return arr[starting subscript]
	if (arr[s] < recursiveMinimum(arr, s + 1, e)) {
		return arr[s];
	}

	return recursiveMinimum(arr, s + 1, e);
}

void exceptionHandler() {
	exceptionGenerator gen;
	printf("Running Exceptions\n");
	try {
		printf("Attempting to divide by 0\n");
		gen.divide(15, 0);
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}

	try {
		printf("Attempting Read Array Out of Bounds Exception\n");
		gen.getElementFromArray(new int[3]{ 4,5,6 }, 3, 3);

	}
	catch (const char* msg) {
		cerr << msg << endl;
	}

	try {
		printf("Attempting Write Array Out of Bounds Exception\n");
		gen.setElementToArray(new int[5]{ 1,2,3,4,0 }, 5, 5, 5);
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}

	try {
		printf("Attempting bad_alloc Exception\n");
		gen.throwBadAlloc();
	}
	catch (bad_alloc& ba) {
		cerr << "Exception: " << ba.what() << endl;
	}

	try {
		printf("Attempting overflow_error Exception\n");
		gen.throwOverflowError();
	}
	catch (overflow_error& oe) {
		cerr << "Exception: " << oe.what() << endl;
	}
}