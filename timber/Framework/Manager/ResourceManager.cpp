#include <vector>
#include "ResourceManager.h"

void ResourceManager::Init()
{
	//Font
	sf::Font fontKOMIKAP;
	fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");

	typedef std::pair<std::string, sf::Font> FontPair;
	fontResource.insert(FontPair("KOMIKAP", fontKOMIKAP));
	
	//Texture
	sf::Texture textureCloud;
	sf::Texture textureBackground;
	sf::Texture textureLog;
	sf::Texture textureAxe;
	sf::Texture textureRIP;
	sf::Texture textureBee;
	sf::Texture textureTree;
	sf::Texture textureBranch;
	sf::Texture textureCharacterback;
	sf::Texture texture1P;
	sf::Texture texture2P;
	std::vector<sf::Texture> texturePlayerType(5);
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
	texturePlayerType[0].loadFromFile("graphics/player1.png");
	texturePlayerType[1].loadFromFile("graphics/player2.png");
	texturePlayerType[2].loadFromFile("graphics/player3.png");
	texturePlayerType[3].loadFromFile("graphics/player4.png");
	texturePlayerType[4].loadFromFile("graphics/player5.png");

	typedef std::pair<std::string, sf::Texture> TexturePair;
	textureResource.insert(TexturePair("Cloud", textureCloud));
	textureResource.insert(TexturePair("Background", textureBackground));
	textureResource.insert(TexturePair("Log", textureLog));
	textureResource.insert(TexturePair("Axe", textureAxe));
	textureResource.insert(TexturePair("RIP", textureRIP));
	textureResource.insert(TexturePair("Bee", textureBee));
	textureResource.insert(TexturePair("Tree", textureTree));
	textureResource.insert(TexturePair("Branch", textureBranch));
	textureResource.insert(TexturePair("Characterback", textureCharacterback));
	textureResource.insert(TexturePair("1P", texture1P));
	textureResource.insert(TexturePair("2P", texture2P));
	textureResource.insert(TexturePair("PlayerTypeA", texturePlayerType[0]));
	textureResource.insert(TexturePair("PlayerTypeB", texturePlayerType[1]));
	textureResource.insert(TexturePair("PlayerTypeC", texturePlayerType[2]));
	textureResource.insert(TexturePair("PlayerTypeD", texturePlayerType[3]));
	textureResource.insert(TexturePair("PlayerTypeE", texturePlayerType[4]));

	//SoundBuffer
	sf::SoundBuffer chopBuffer;
	sf::SoundBuffer deathBuffer;
	sf::SoundBuffer ootBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	deathBuffer.loadFromFile("sound/death.wav");
	ootBuffer.loadFromFile("sound/out_of_time.wav");

	typedef std::pair<std::string, sf::SoundBuffer> SoundPair;
	soundResource.insert(SoundPair("chop", chopBuffer));
	soundResource.insert(SoundPair("death", deathBuffer));
	soundResource.insert(SoundPair("oot", ootBuffer));
}

sf::Font* ResourceManager::GetFont(std::string fontName)
{
	sf::Font* font = new sf::Font;
	*font = fontResource.find(fontName)->second;
	return font;
}

sf::Texture* ResourceManager::GetTexture(std::string textureName)
{
	sf::Texture* texture = new sf::Texture;
	*texture = textureResource.find(textureName)->second;
	return texture;
}

sf::SoundBuffer* ResourceManager::GetSoundBuffer(std::string soundName)
{
	sf::SoundBuffer* soundBuffer = new sf::SoundBuffer;
	*soundBuffer = soundResource.find(soundName)->second;
	return soundBuffer;
}

//For Singleton
ResourceManager::ResourceManager()
{
}
ResourceManager::ResourceManager(const ResourceManager& ref)
{
}
ResourceManager::~ResourceManager()
{
}
ResourceManager& ResourceManager::GetInstance()
{
	static ResourceManager instance;
	return instance;
}