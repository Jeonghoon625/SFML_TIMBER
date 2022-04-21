#include "TimerBar.h"

TimerBar::TimerBar() : timerBarSize(Vector2f(timerBarWidth, timerBarHeight)), timerPos(Vector2f(1920 * 0.5f - timerBarWidth * 0.5f, 980.f)), timerBarWidthPerSecond(timerBarWidth / timeMax)
{
    timerBar.setSize(timerBarSize);
    timerBar.setPosition(timerPos);
    timerBar.setFillColor(Color::Red);
}