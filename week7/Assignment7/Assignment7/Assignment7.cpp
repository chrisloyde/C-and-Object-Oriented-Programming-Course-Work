/*
Exercise 16.8, 16.9, 16.10 

Exercise 16.8 (Duplicate Elimination): 
	Reads 20 integers into an array, uses unique alogirthm to reduce the array to the unique values entered
	by the user, and uses the copy algorithm to display unique values.
Exercise 16.9 (Duplicate Elimination): 
	Modification of Exercise 16.8 except using the unique_copy algorithm. Unique values are inserted into
	an empty vector. back_inserter is used to enable vector to grow as new items are added, and copy algorithm is used to display unique values.
Exercise 16.10 (Reading Data from File): 
	Uses istream_iterator<int>, the copy alogrithm, and a back-inserter to read the contents of a text file
	that contains int values seperated by whitespace. Int values are placed into a vecotr. 
*/

#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

void duplicateElimination();
void duplicateEliminationVector();
void dataFromFile();

int main() {
	int in = 0;
	while (in != -1) {
		printf("Enter 1 for Exercise 16.8\nEnter 2 for Exercise 16.9\nEnter 3 for Exercise 16.10\nEnter -1 to quit\n");
		cin >> in;
		switch (in) {
		case 1: duplicateElimination(); break;
		case 2: duplicateEliminationVector(); break;
		case 3: dataFromFile(); break;
		case -1: in = -1; break;
		default: printf("Invalid Input\n"); break;
		}
	}
	return 0;
}

// Function for exercise 16.8
void duplicateElimination() {
	printf("Running Exercise 16.8\n");
	int const SIZE = 20; 
	array <int, SIZE> intArr; // intialize size 20 array.
	printf("Enter 20 integers: ");
	// get input
	istream_iterator<int> input{ cin }; // intialize an iterator to read cin
	ostream_iterator<int> output{ cout, " " }; // intialize an iterator to output.

	// get the number of inputs require to fill array
	for (int i = 0; i < SIZE; ++i) {
		intArr[i] = *input; // dereference value in input and store in array which is represented by the dereference iterator.
		if (i != SIZE - 1) { //  stop incrementing input once we are about to read the last input.
			input++; // increment input to get the next user input from cin
		}
	}
	// sort array, must do this since unique requires a sorted array
	sort(intArr.begin(), intArr.end());
	// use unique algorithm, reduce array to only unique values
	// unique returns an iterator to the element after the end of the sorted unique sequence.
	auto end = unique(intArr.begin(), intArr.end());
	// use copy algorithm, print array
	// iterate between beginning and where unique determined the end.
	copy(intArr.begin(), end , output);
	printf("\n");

	cin.clear();
	system("pause");
}

// Function for exercise 16.9
void duplicateEliminationVector() {
	printf("Running Exercise 16.9\n");
	int const SIZE = 20;
	vector<int> intVect;
	vector<int> copVect;

	printf("Enter 20 integers: ");
	istream_iterator<int> input{ cin }; // intialize an iterator to read cin
	ostream_iterator<int> output{ cout, " " }; // intialize an iterator to output.

	for (int i = 0; i < SIZE; ++i) {
		intVect.push_back(*input); // push each new input into back of vector
		if (i != SIZE - 1) {
			input++;
		}
	}
	// sort vectors before we can use other algorithms
	sort(intVect.begin(), intVect.end());
	// unique copy to insert unique elements into a new vector
	// uses back_inserter to dynamically resize new vector
	unique_copy(intVect.begin(), intVect.end(), back_inserter(copVect));

	// output
	cout << "Original Vector: "; copy(intVect.begin(), intVect.end(), output);
	cout << "\nUnique Vector: "; copy(copVect.begin(), copVect.end(), output);
	cout << endl;

	cin.clear();
	system("pause");
}

// Function for exercise 16.10
void dataFromFile() {
	printf("Running Exercise 16.10\n");
	vector<int> storage;
	// open a basic text file
	ifstream file{"file1.txt"};
	if (!file.is_open()) {
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	printf("File opened succesfully\n");
	istream_iterator<int> file_it(file); // iterator for file
	istream_iterator<int> eof; // default constructor acts as end of file
	ostream_iterator<int> output{ cout, " " };

	// copy integers from file and store in storage vector using back_inserter
	copy(file_it, eof, back_inserter(storage));
	// display contents of vector
	printf("File contains: "); copy(storage.begin(), storage.end(), output);
	printf("\n");
	// close file
	file.close();

	cin.clear();
	system("pause");
}