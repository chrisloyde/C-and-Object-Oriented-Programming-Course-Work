/*
Exercise 9.23

Exercise 9.23 (Card Shuffling and Dealing):
	Program shuffles and deals from a deck of cards. The program consists
	of a Card and DeckOfCards class and a driver program.

	Class Card should provide:
		a. Data members face and suit (enumerations)
		b. Constructor that recieves two enumeration constants representing the face and suit
		c. Two static arrays of strings representing the faces and suits
		d. A toString function that returns the Card as a string in the form "face of suit"
	Class DeckOfCards
		a. An array of cards named deck to store the cards.
		b. An integer currentCard representing the next card to deal.
		c. A default constructor that initializes the Cards in the deck
		d. A shuffle function that shuffles the Cards in the deck.
			The shuffle algorithm should iterate through the array of cards. For
			each card, randomly select another card in the deck and swap the two cards.
		e. A dealCard function that returns the next card object from the deck.
		f. A moreCards function that returns bool value indicating whether there are more Cards to deal.
	Driver Program:
		Create DeckOfCards, shuffle cards, then deal the 52 cards.

*/

#include <iostream>;
#include "Card.h"
#include "DeckOfCards.h"

#define DECK_SIZE 52

int printDeck(DeckOfCards *deck); // returns number of cards in deck

int main() {
	DeckOfCards *deck = new DeckOfCards(); //initialize Deck
	deck->shuffle(); // shuffle Deck
	printDeck(deck); // print results
	
	printf("\nPress Enter to Exit\n"); getchar();
	delete deck; // free deck
	return 0;
}

int printDeck(DeckOfCards *deck) {
	int counter = 0;
	// while the deck contains more cards, print the name of the card.
	while (deck->moreCards()) {
		for (int i = 0; i < 4; i++) {
			printf("%-20s", deck->dealCard().toString().c_str());
			++counter;
		}
		printf("\n");
	}
	return counter;
}