#include "Bee.h"

Bee::Bee()
{
    textureBee.loadFromFile("graphics/bee.png");
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(2000, 500);
}
