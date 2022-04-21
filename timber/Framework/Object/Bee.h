#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bee
{
private:
    Texture textureBee;
    Sprite spriteBee;
    bool beeActive = false;
    float beeSpeed = 0.0f;

public:
	Bee();

};