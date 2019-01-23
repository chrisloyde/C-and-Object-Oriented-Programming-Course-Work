#include <iostream>
#include <string>
#include <time.h>
/*
Assignment 4: Exercise 6.57 & 6.58

Exercise 6.57: Program helps elementary-school students learn multiplication.
Uses rand function to produce 2 positive one-digit integers then prompts the
user to enter the answer, checks the answer and provides feedback with the ability
to try agian.

Exercise 6.58: Exact same as exercise 6.57 except now the program has various different
responses.

I've decided to just combine the two exercises into one program rather then copying-pasting
into two different exercises that have the same function.
*/

int assignment4();
void generateQuestion(std::string*, size_t);

int main() {
	assignment4();
	return 0;
}

int assignment4() {
	// string array containing both negative and positive responses.
	// there should always be equal amount of positive and negative responses.
	// list all positive responses then negative responses.
	std::string responses[8];
	responses[0] = "Very good!";
	responses[1] = "Excellent!";
	responses[2] = "Nice work!";
	responses[3] = "Keep up the good work!";
	responses[4] = "No. Please try again.";
	responses[5] = "Wrong. Try once more";
	responses[6] = "Don't give up!";
	responses[7] = "No. Keep trying.";

	while (true) {
		generateQuestion(responses,8);
	}
	return system("pause");
}

// creates a multiplication question prompt
void generateQuestion(std::string *responses, size_t size) {
	int a{ 0 }; int b{ 0 };
	int in{ 0 }, answer{ 0 };
	int responseKey{ 0 };
	// generate 2 numbers between 0 and 10
	srand(time(0));
	a = rand() % 10;
	b = rand() % 10;
	printf("How much is %d times %d?", a, b);
	answer = a * b; // calulate the answer

	do {
		scanf("%d", &in); // scan for user input
		// generate a random number between 0 and half the size of our response array - 1.
		// subtracting one is important because we need to consider the inclusion of 0
		responseKey = rand() % ((size/2)-1); 
		// if answer is incorrect print prompt stating and loop runs again
		if (in != answer) {
			// All negative responses are half the size away so add half the size to the 
			// random number generated.
			printf("%s\n", responses[responseKey+(size/2)].c_str());
		}
		// if answer is correct print prompt and loop ends
		else {
			// all positive resopnses are in the first half so we just need the randomly generated
			// key.
			printf("%s\n", responses[responseKey].c_str());
		}
	} while (in != answer); // loop only while answer is incorrect
}