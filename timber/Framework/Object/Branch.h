#pragma once
#include <SFML/Graphics.hpp>
#include "Enum.h"

using namespace sf;

class Branch
{
private:
    const int countBranches = 6;
	Texture textureBranch;
    Sprite* spriteBranches;
    side* sideBranches;

public:
	Branch();
	~Branch();
};

