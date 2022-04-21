#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class TextManager
{
private :
    Font fontKOMIKAP;
    FloatRect textRect;
    Text textMessage;
    Text textScore;

public:
    TextManager();
    float GetCenterX(FloatRect textRect);
    float GetCenterY(FloatRect textRect);
};

