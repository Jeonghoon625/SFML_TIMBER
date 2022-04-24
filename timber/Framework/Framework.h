#pragma once
#include <SFML/Graphics.hpp>
#include "Manager/ResourceManager.h"
#include "Manager/SceneManager.h"
#include <string>

class Framework
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;

	SceneManager sceneManager;

public:
	void Init(int screenWidth, int screenHeight, std::string gameTitle);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	int Run();
};