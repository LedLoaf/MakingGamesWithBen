#pragma once
#include <Windows.h>

class Timer
{
	LARGE_INTEGER startTime;
	double fFreq;

public:
	Timer();

	void reset();

	// Gets the most up to date time.
	double getTime() const;
};
