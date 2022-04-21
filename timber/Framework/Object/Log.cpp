#include "Log.h"

Log::Log()
{
    textureLog.loadFromFile("graphics/log.png");
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);
}