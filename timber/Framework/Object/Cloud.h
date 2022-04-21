#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cloud
{
private:
	const int countClouds = 3;
	Texture textureCloud;
	Sprite* spriteClouds;
	bool* cloudsActive; // = false;
	float* cloudsSpeed; // = 0.0f;

public:
	Cloud();
	~Cloud();
};

