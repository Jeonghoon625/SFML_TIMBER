#pragma once
#include <SFML/Graphics.hpp>
#include "Timer.h"

using namespace sf;

class TimerBar
{
private:
    RectangleShape timerBar;
    float timerBarWidth = 400;
    float timerBarHeight = 80;
    Vector2f timerBarSize;
    Vector2f timerPos;
    float timerBarWidthPerSecond;

public:
    TimerBar();
};

