#include "Cloud.h"

Cloud::Cloud()
{
	textureCloud.loadFromFile("graphics/cloud.png");

	spriteClouds = new Sprite[countClouds];
	cloudsActive = new bool[countClouds]; // = false;
	cloudsSpeed = new float[countClouds]; // = 0.0f;

	for (int i = 0; i < countClouds; ++i)
	{
		spriteClouds[i].setTexture(textureCloud);
		spriteClouds[i].setPosition(2000, 150 * i);
		cloudsActive[i] = false;
		cloudsSpeed[i] = 0.0f;
	}
}

Cloud::~Cloud()
{
	delete[] spriteClouds;
	delete[] cloudsActive;
}