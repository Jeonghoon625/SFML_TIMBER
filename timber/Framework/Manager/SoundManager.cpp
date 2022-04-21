#include "SoundManager.h"

SoundManager::SoundManager()
{
    chopBuffer.loadFromFile("sound/chop.wav");
    chop.setBuffer(chopBuffer);

    deathBuffer.loadFromFile("sound/death.wav");
    death.setBuffer(deathBuffer);

    ootBuffer.loadFromFile("sound/out_of_time.wav");
    oot.setBuffer(ootBuffer);
}