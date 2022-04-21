#pragma once
#include <SFML/Graphics.hpp>
#include "Enum.h"

using namespace sf;

class Axe
{
private:
    Texture textureAxe;
    Sprite spriteAxe;
    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

public:
	Axe();
    void Move(side side);
};