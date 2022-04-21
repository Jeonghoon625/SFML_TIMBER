#pragma once
#include <SFML/Graphics.hpp>
#include "Enum.h"

using namespace sf;

class Log
{
private:
    Texture textureLog;
    Sprite spriteLog;

    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

public:
    Log();
};

