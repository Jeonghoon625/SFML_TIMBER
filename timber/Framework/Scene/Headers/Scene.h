#pragma once
#include <SFML/Graphics.hpp>
#include "../../Framework/Manager/SceneManager.h"

class Scene
{
protected:
	SceneManager sceneManager;

public:
	Scene(SceneManager sceneManager);

	virtual void Init() = 0;
	virtual void Updata(float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow* window) = 0;
};