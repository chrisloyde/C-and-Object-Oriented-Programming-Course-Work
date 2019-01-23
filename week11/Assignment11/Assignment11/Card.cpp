#include "Card.h"

string Card::faces[14]{"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
string Card::suits[4]{ "Hearts", "Spades", "Clubs", "Diamonds" };

Card::Card(face_types f, suit_types s)
{
	faceType = f;
	suitType = s;

	// Give the card its name as a string on creation.
	cardName.append(faces[(int)faceType] + " of " + suits[(int)suitType]);
}

string Card::toString() {
	return cardName;
}

Card::~Card()
{
	// no dynamic memory is allocated so nothing to free.
}
