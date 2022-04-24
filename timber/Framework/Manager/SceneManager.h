#pragma once
#include "SFML/Graphics.hpp"
#
class SceneManager
{
private:
	
public:
	void Init();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
};