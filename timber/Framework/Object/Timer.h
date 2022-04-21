#pragma once
#define timeMax 6.0
#include <SFML/Graphics.hpp>

using namespace sf;

class Timer
{
private:
    Clock clock;
    float timeRemaining;

public:
    Timer();
    Clock GetClock();

    float GetTimeRemaining();
    void SetTimeRemaining(float remain);

    const float GetTimeMax();
};


