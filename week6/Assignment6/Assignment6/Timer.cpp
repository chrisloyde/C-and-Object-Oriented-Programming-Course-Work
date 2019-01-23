#include "Timer.h"
Timer::Timer()
{
	isStarted = false;
	startTick = true;
	startTick = 0;
}

void Timer::start() {
	startTick = clock();
	isStarted = true;
}

unsigned long Timer::getElapsed() {
	return isStarted ? ((unsigned long)clock() - startTick) / CLOCKS_PER_SEC : 0;
}

Timer::~Timer()
{
}
