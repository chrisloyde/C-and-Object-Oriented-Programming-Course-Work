/*
Exercise 21.11 & 21.12 (pg. 896)

Exercise 21.11 (Hangman Game):
	Plays the game Hangman: From a list of words, pick one and display the following:
		Guess the word: XXXXXX
	Each X represents a letter and the user tries to guess the letters in the word.
	When the user guesses a letter an appropriate response is given, if the letter is incorrect
	then an additional part of the hangman is printed.
	At game end, the user is asked to play again.

Exercise 21.12 (Printing a string Backward): 
	Program inputs a string and prints the strinbg backwards.
	Converts all uppercase characters to lowercase
	Converts all lowercase characters to uppercase
*/

#include <iostream>
#include <random>
#include <ctime>
#include <string>

#define NUM_OF_WORDS 15
#define WORD_LENGTH 20

char words[NUM_OF_WORDS][WORD_LENGTH] = {
	"Cat", "Turtle", "Horse", "Dog", "Bird",
	"Lion", "Albatross", "Iguana", "Spider","Gerbil", 
	"Hamster", "Aligator", "Cow", "Sloth", "Octopus"
};

void playHangman();
int isCharInStr(const char *aString, char c, char *gString);
void printFigure(int numOfParts);

void reverseStr(char *str, int size);

int main() {
	int in = 0;
	do {
		printf("1 - Hangman Game(Exercise 21.11)\n2 - Printing a String Backward(Exercise 21.12)\n-1 - Quit\n");
		scanf("%d", &in);
		if (in == 1) { // do hangman
			// hangman variables
			bool playing = true;
			char buff[8]; // input buffer
			// hangman loop
			do {
				playHangman();
				printf("Play again? yes/no ");
				scanf("%s", buff);
				if (strcmp(buff, "yes") != 0) {
					playing = false;
				}
			} while (playing);
		}
		else if (in == 2) { // do reverse string
			char buff[64]; // input buffer
			printf("Enter String: ");
			getchar(); // clear buffer
			fgets(buff,64,stdin);
			reverseStr(buff, strlen(buff));
		}
		else if (in == -1) {
			in = -1;
		}
	} while (in != -1);
	getchar();
	return 0;
}

void playHangman() {
	srand(time(0));
	char *word = nullptr;
	char *gWord = nullptr;
	bool quit = false;
	int incorrect = 0;
	int matching = 0;
	int temp;
	int total = 0;
	char gLetter;
	word = words[rand() % NUM_OF_WORDS];
	
	gWord = (char *)malloc(strlen(word));
	for (int i = 0; i < strlen(word); i++) {
		gWord[i] = 'X';
	}

	while (!quit) {
		printFigure(incorrect);
		// print prompt to guess word, as well as X's.
		printf("Guess the word: \t");
		for (int i = 0; i < strlen(word); i++) {
			printf("%c", gWord[i]);
		}
		printf("\n");

		scanf(" %c", &gLetter); // get letter from input
		temp = isCharInStr(word, gLetter, gWord);
		if (temp == 0) {
			printf("No\n");
			++incorrect; // increment the number of incorrects if there is no matching
		}
		else {
			printf("Yes\n");
		}
		matching += temp;
		temp = 0;

		// if incorrect is 7 or player guess the answer then end the game
		if (incorrect >= 7) {
			printFigure(incorrect);
			printf("%s\n", word);
			printf("You were hanged. ");
			quit = true;
		}
		if (matching >= strlen(word)) {
			printFigure(incorrect);
			printf("%s\n", word);
			printf("Congratulations!!! You guessed my word. ");
			quit = true;
		}
	}
	delete[] gWord;
}

// parameters: answer string, character being guessed, string that holds X's
// Check if the character occurs anywhere in the answer string, then add it to
// the correspoding position in the gStr. Meaning it will replace the X with the proper
// character.
// returns number of matching characters
int isCharInStr(const char *str, char c, char *gStr) {
	int matching = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (c == str[i] || c == toupper(str[i]) || toupper(c) == str[i]) {
			// ensure that this letter has not already been guessed.
			if (gStr[i] == 'X') {
				gStr[i] = str[i];
				++matching;
			}
		}
	}
	return matching;
}

// based on the number of body parts to print, print peices of the hanged mans body.
void printFigure(int n) {
	char body[7]{'0','|','/','\\','|','/','\\'};

	if (n < 0) {
		n = 0;
	}
	if (n > 7) {
		n = 7;
	}

	if (n >= 0) {
		printf("\n");
	}
	if (n >= 1) {
		// print head in all cases greater then 1
		printf(" %c\n", body[0]);
	}
	if (n == 2) {
		// print midsection if 2 body parts
		printf(" %c\n", body[1]);
	}
	if (n == 3) {
		// print midsection and left arm if 3 body parts
		printf("%c%c\n", body[2], body[1]);
	}
	if (n >= 4) {
		// print midsection and both arms if greater then or equal to 4 body parts.
		printf("%c%c%c\n", body[2], body[1], body[3]);
	}
	if (n >= 5) {
		// print lower section if greater then or equal to 5 body parts.
		printf(" %c\n", body[4]);
	}
	if (n == 6) {
		// print left leg if 6 body parts.
		printf("%c\n", body[5]);
	}
	if (n == 7) {
		// print left and right leg if 7 body parts.
		printf("%c %c\n", body[5], body[6]);
	}
	printf("\n");
}

// prints the reversal of a string, also changing lowercase to uppercase and vice versa.
void reverseStr(char *str, int size) {
	// reverse backwards through string
	for (int i = (size - 1); i >= 0; i--) {
		// using the ASCII table determine if character is lowercase or uppercase, and convert appropriatles
		if ((int)str[i] >= 65 && (int)str[i] <= 90) {
			printf("%c", tolower(str[i]));
		} 
		else if ((int)str[i] >= 97 && (int)str[i] <= 122) {
			printf("%c", toupper(str[i]));
		}
		else {
			// if it is not a letter, just print it as normal.
			printf("%c", str[i]);
		}
	}
	printf("\n\n");
}