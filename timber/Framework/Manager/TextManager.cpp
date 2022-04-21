#include "TextManager.h"

TextManager::TextManager()
{
    fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");

    textMessage.setFont(fontKOMIKAP);
    textMessage.setString("Press Enter to start!");
    textMessage.setCharacterSize(75);
    textMessage.setFillColor(Color::White);
    textRect = textMessage.getLocalBounds();
    textMessage.setOrigin(GetCenterX(textRect), GetCenterY (textRect));
    textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

    textScore.setFont(fontKOMIKAP);
    textScore.setString("Score = 0");
    textScore.setCharacterSize(100);
    textScore.setFillColor(Color::White);
    textScore.setPosition(20, 20);
}

float TextManager::GetCenterX(FloatRect textRect)
{
    return textRect.left + textRect.width * 0.5f;
}

float TextManager::GetCenterY(FloatRect textRect)
{
    return textRect.top + textRect.height * 0.5f;
}

