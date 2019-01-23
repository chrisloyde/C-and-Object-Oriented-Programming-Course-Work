#pragma once
#include <string>

using namespace std;
class Card
{
public:
	enum face_types {one, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
	enum suit_types {hearts, spades, clubs, diamonds};
	static string faces[14];
	static string suits[4];

	Card(face_types faceType, suit_types suitType);
	string toString();
	~Card();
private:
	face_types faceType;
	suit_types suitType;
	string cardName;
};

