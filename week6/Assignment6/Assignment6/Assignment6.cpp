/*
Exercise 8.12 (Simulation: The Tortoise and the Hare)

Runs a simulation of the race between the Hare and the Tortoise racing on a slipperly mountain.
There are 70 squares total and the contestants(Hare and Tortoise) start on square 1.
Each second the simulation updates (changes position of contestants) and prints race information into console.
The simulation only updates once per second.
When a contestant reaches square 70 the contestant wins and the simulation ends.

*/

#include <cstdio>
#include "Timer.h"
#include "Animal.h"
#include <random>
#include <time.h>

int simulateRace();
void drawRace(Animal *, Animal *);
void moveTortoise(Animal *t);
void moveHare(Animal *h);


int main() {
	simulateRace();
	getchar();
	return 0;
}

int simulateRace() {
	Timer timer; // initialize timer
	timer.start(); // start timer
				   // intialize time tracking variables
	int currentTime = 0, prevTime = -1;
	int winner = -1; // 0 for hare, 1 for tortoise

	bool isRunning = true;
	srand(time(0)); // call srand to generate a random seed
	// initialize animals
	Animal *hare = new Animal();
	hare->setType(Animal::hare);
	Animal *tort = new Animal();
	tort->setType(Animal::tortoise);
	printf("Chris Peterson\nCIS278\nExercise 8.12\n\n");
	printf("BANG !!!!!\nAND THEY'RE OFF !!!!!\n");

	// Game loop
	while (isRunning) {
		// get the current time at the start of the loop.
		currentTime = timer.getElapsed();
		// if the time has changed then tick
		// since program requires 1 tick per second, this is where the game will run
		if (currentTime != prevTime) {
			// move animals
			moveTortoise(tort);
			moveHare(hare);
			// "render" screen
			drawRace(hare, tort);

			// its important to note that rendering the screen also checks whether the tortoise
			// or hare are colliding, we want to do this after moving the animals for 2 reasons.
			// 1. If we rendered before we did initial moves, the first screen would display OUCH on position 1.
			// 2. While, its not important for this program, updating (moving) after rendering causes weird lag
			//		since the game has drawn everything before rendering, and in this simulation's case, the actual
			//		screen rendering will be 1 second behind, meaning positions might not match up and win condition
			//		may display before it appears anything has finished the race.

			// check win conditions
			if (hare->getPos() == 70 && tort->getPos() == 70) {
				printf("THERE IS NO TIE IN THIS RACE! TORTOISE WINS!!!\n");
				isRunning = false;
				winner = 1; // tortoise win
			}
			else if (hare->getPos() == 70) {
				printf("Hare wins. Yuch.\n");
				isRunning = false;
				winner = 0; // hare win
			}
			else if (tort->getPos() == 70) {
				printf("TORTOISE WINS!!! YAY!!!\n");
				isRunning = false;
				winner = 1;// tortoise win
			}
		}

		// at the end of the loop assign the current time to previous time.
		prevTime = currentTime;
	}
	return winner;
}

void drawRace(Animal *hare, Animal *tort) {
	// draw positions
	for (int i = 1; i < 71; i++) {
		// if i position is not shared with tortoise or hare print a line
		if (i != hare->getPos() && i != tort->getPos()) {
			printf("-");
		}
		else {
			// if i position contains both tortoise and hare print ouch
			if (hare->getPos() == tort->getPos()) {
				printf("ouch!");
			}
			else {
				// if i position holds hare print H
				if (hare->getPos() == i) {
					printf("H");
				}
				// if i position holds tortoise print T
				if (tort->getPos() == i) {
					printf("T");
				}
			}
		}
	}
	printf("\n");
}

void moveTortoise(Animal *t) {
	int x;
	x = rand() % 10 + 1; // generate number between 1 and 10
	// between 1 and 5
	if (x <= 5) {
		// perform 'fast plod'
		t->setPos(3,1); // move 3 spaces forward.
	}
	else if (x <= 7) {
		// perform 'slip'
		t->setPos(6, -1); // move 6 spaces backwards.
	}
	else if (x <= 10) {
		// perform 'slow plod'
		t->setPos(1, 1); //move 1 square forwards.
	}
}

void moveHare(Animal *h) {
	int x;
	x = rand() % 10 + 1; // generate number between 1 and 10
	if (x <= 2) {
		// perform 'sleep'
		// nothing happens
	}
	else if (x <= 4) {
		// perform 'big hop'
		h->setPos(9, 1); // move 9 spaces forwards
	}
	else if (x <= 5) {
		// perform 'big slip'
		h->setPos(12, -1); // move 12 spaces backwards
	}
	else if (x <= 8) {
		// perform 'small hop'
		h->setPos(1, 1); // move 1 space forwards
	}
	else if (x <= 10) {
		// perform 'small slip'
		h->setPos(2, -1); // move 2 space backwards
	}
}