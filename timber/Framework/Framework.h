#pragma once
#include "SFML/Graphics.hpp"
#include "Manager/ResourceManager.h"

using namespace sf;

class Framework
{
private:
	VideoMode vm;
	RenderWindow window; 
	Clock clock;

public:
	Framework();
	void Init();
	void Update();
	bool windowIsOpen();
};