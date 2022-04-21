#include "RIP.h"

RIP::RIP()
{
    textureRIP.loadFromFile("graphics/rip.png");
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);
}