#pragma once
#include "../Macro.h"
#include "../Enum.h"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

using namespace sf;

class ResourceManager
{
private:
	Font fontKOMIKAP;

	Texture textureCloud;
	Texture textureBackground;
	Texture textureLog;
	Texture textureAxe;
	Texture textureRIP;
	Texture textureBee;
	Texture textureTree;
	Texture textureBranch;
	Texture textureCharacterback;
	Texture texture1P;
	Texture texture2P;
	Texture textureList[CHARACTER_MAX];
	
	SoundBuffer chopBuffer;
	SoundBuffer deathBuffer;
	SoundBuffer ootBuffer;
	
public:
	void Init();
	Texture GetTexture(TextureName name);
	Font GetFont(FontName name);
	SoundBuffer GetSoundBuffer(SoundBufferName name);
};