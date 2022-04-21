#include "Timer.h"

Timer::Timer() : timeRemaining(timeMax)
{
}

const float Timer::GetTimeMax()
{
	return timeMax;
}

float Timer::GetTimeRemaining()
{
	return timeRemaining;
}

void Timer::SetTimeRemaining(float remain)
{
	timeRemaining = remain;
}

Clock Timer::GetClock()
{
	return clock;
}