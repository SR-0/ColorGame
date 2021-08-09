#include "Manager/EventManager.h"
#include "Manager/InputManager.h"
#include "Core/RenderWindow.h"

RenderWindow* EventManager::renderWindow = nullptr;

bool EventManager::initialize(RenderWindow& renderWindow)
{
	attachRenderWindow(renderWindow);

	return true;
}

void EventManager::update()
{
	sf::Event event;

	if (renderWindow)
	{
		while (renderWindow->pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					renderWindow->close();
				}
				break;

				case sf::Event::KeyPressed:
				{
					im::handle(event.key, true);
				}
				break;

				case sf::Event::KeyReleased:
				{
					im::handle(event.key, false);
				}
				break;
			}
		}
	}
	else
	{
		// to do debugger
	}
}

void EventManager::terminate()
{
	detachRenderWindow();
}

void EventManager::attachRenderWindow(RenderWindow& renderWindow)
{
	EventManager::renderWindow = &renderWindow;
}

void EventManager::detachRenderWindow()
{
	renderWindow = nullptr;
}
