#include "Timer.h"



Timer::Timer()
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	fFreq = (double)freq.QuadPart;
	reset();
}

void Timer::reset()
{
	QueryPerformanceCounter(&startTime);
}

double Timer::getTime() const
{
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);
	return (endTime.QuadPart - startTime.QuadPart) / fFreq;
}
