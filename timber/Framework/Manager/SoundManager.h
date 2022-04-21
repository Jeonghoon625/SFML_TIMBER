#pragma once
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager
{
private:
    SoundBuffer chopBuffer;
    SoundBuffer ootBuffer;
    SoundBuffer deathBuffer;
    Sound chop;
    Sound oot;
    Sound death;
    
public:
    SoundManager();
};

