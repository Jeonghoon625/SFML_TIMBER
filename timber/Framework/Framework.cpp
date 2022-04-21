#include "Framework.h"

Framework::Framework() : vm(1920, 1080), window(vm, "Timber!", Style::Default)
{
}

void Framework::Init()
{
	resourceManager.Init();
}

void Framework::Update()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
				break;
			}

		default:
			break;
		}
	}
}

bool Framework::windowIsOpen()
{
	return window.isOpen();
}
