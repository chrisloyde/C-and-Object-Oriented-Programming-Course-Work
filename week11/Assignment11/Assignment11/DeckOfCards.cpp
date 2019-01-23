#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	srand(time(0)); // set random seed at creation of deck

	int d = 0;
	// iterate through 52 cards
	while (d < DECK_SIZE) {
		// iterate through the 13 faces (52/4)
		for (int f = 0; f < numOfFaces; f++) {
			// iterate through the 4 suits
			for (int s = 0; s < numOfSuits; s++) {
				// create a new card at the current iteration of deck, with values according to the face and suit iterations
				// we can cast the ints to the enumerators since their values match numerical positions.
				deck[d] = new Card((Card::face_types) f, (Card::suit_types)s);
				d++; // increment deck since a card was created.
			}
		}
	}
}

void DeckOfCards::shuffle() {
	int r; // integer to store random number
	Card *tempCard; // Card pointer to store a card temporarily while it is being replaced
	for (int i = 0; i < DECK_SIZE; i++) {
		tempCard = deck[i]; // assign the temporary card to the current postion
		r = rand() % DECK_SIZE; // get a random value between 0 and 52
		deck[i] = deck[r]; // assign the card at the current position to the card at the random position
		deck[r] = tempCard; // assign the card at the random position to the temp card (storing the card that was at current position)
	}
}

Card DeckOfCards::dealCard() {
	// before incrementing the current card, store the card we are currently dealing
	int prevCard = currentCard;
	++currentCard;
	// return the card to deal.
	return *deck[prevCard];
}

bool DeckOfCards::moreCards() {
	return (currentCard < DECK_SIZE ? true : false);
}

DeckOfCards::~DeckOfCards()
{
	for (int i = DECK_SIZE-1; i >= 0; i--) {
		delete deck[i];
	}
}
