#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

class ResourceManager
{ 
private:
	std::map<std::string, sf::Font> fontResource;
	std::map<std::string, sf::Texture> textureResource;
	std::map<std::string, sf::SoundBuffer> soundResource;
	
public:
	void Init();

	sf::Font GetFont(std::string fontName);
	sf::Texture GetTexture(std::string textureName);
	sf::SoundBuffer GetSoundBuffer(std::string soundName);
};