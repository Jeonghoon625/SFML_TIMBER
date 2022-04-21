#include "Axe.h"

Axe::Axe()
{
    textureAxe.loadFromFile("graphics/axe.png");
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);
}

void Axe::Move(side side)
{   
}