#pragma once
#include "Card.h"
#include <random>
#include <ctime>

#define DECK_SIZE 52
#define numOfFaces 13
#define numOfSuits 4

class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle(); // shuffles the deck
	Card dealCard(); // returns the next card in the deck
	bool moreCards(); // returns true if there are more cards in the deck, false otherwise.
	~DeckOfCards();
private:
	Card * deck[52];
	int currentCard = 0;
};

