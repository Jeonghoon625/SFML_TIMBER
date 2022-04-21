#include "ResourceManager.h"

void ResourceManager::Init()
{
	fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");

	textureRIP.loadFromFile("graphics/rip.png");
	textureAxe.loadFromFile("graphics/axe.png");
	textureLog.loadFromFile("graphics/log.png");
	textureBackground.loadFromFile("graphics/background.png");
	textureCloud.loadFromFile("graphics/cloud.png");
	textureBee.loadFromFile("graphics/bee.png");
	textureTree.loadFromFile("graphics/tree.png");
	textureBranch.loadFromFile("graphics/branch.png");
	textureCharacterback.loadFromFile("graphics/back.png");
	texture1P.loadFromFile("graphics/1P.png");
	texture2P.loadFromFile("graphics/2P.png");
	textureList[0].loadFromFile("graphics/player1.png");
	textureList[1].loadFromFile("graphics/player2.png");
	textureList[2].loadFromFile("graphics/player3.png");
	textureList[3].loadFromFile("graphics/player4.png");
	textureList[4].loadFromFile("graphics/player5.png");

	chopBuffer.loadFromFile("sound/chop.wav");
	deathBuffer.loadFromFile("sound/death.wav");
	ootBuffer.loadFromFile("sound/out_of_time.wav");
}

Font ResourceManager::GetFont(FontName name)
{
	Font font;

	switch (name)
	{
	case FontName::fontKOMIKAP:
		font = fontKOMIKAP;
		break;

	default:
		break;
	}

	return font;
}

SoundBuffer ResourceManager::GetSoundBuffer(SoundBufferName name)
{
	SoundBuffer soundBuffer;

	switch (name)
	{
	case SoundBufferName::chopBuffer:
		soundBuffer = chopBuffer;
		break;

	case SoundBufferName::deathBuffer:
		soundBuffer = deathBuffer;
		break;

	case SoundBufferName::ootBuffer:
		soundBuffer = ootBuffer;
		break;

	default:
		break;
	}

	return soundBuffer;
}

Texture ResourceManager::GetTexture(TextureName name)
{
	Texture texture;

	switch (name)
	{
	case TextureName::textureCloud:
		texture = textureCloud;
		break;

	case TextureName::textureBackground:
		texture = textureCloud;
		break;

	case TextureName::textureLog:
		texture = textureCloud;
		break;

	case TextureName::textureAxe:
		texture = textureCloud;
		break;

	case TextureName::textureRIP:
		texture = textureCloud;
		break;

	case TextureName::textureBee:
		texture = textureCloud;
		break;

	case TextureName::textureTree:
		texture = textureCloud;
		break;

	case TextureName::textureBranch:
		texture = textureCloud;
		break;

	case TextureName::textureCharacterback:
		texture = textureCloud;
		break;

	case TextureName::texture1P:
		texture = textureCloud;
		break;

	case TextureName::texture2P:
		texture = textureCloud;
		break;

	case TextureName::textureList:
		texture = textureCloud;
		break;
	}

	return texture;
}