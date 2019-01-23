#pragma once

#include <time.h>
class Timer {
private:
	unsigned long startTick;
	bool isStarted;
public:
	void start();
	unsigned long getElapsed();
	Timer();
	~Timer();
};

