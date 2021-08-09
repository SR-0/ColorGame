#include "Manager/InputManager.h"

#include "Asset/SoundBuffer.h"
#include "Asset/Sound.h"
#include "Asset/Music.h"
#include "Asset/Font.h"
#include "Asset/Texture.h"
#include "Asset/Shape.h"
#include "Asset/RectangleShape.h"
#include "Asset/CircleShape.h"
#include "Asset/ConvexShape.h"
#include "Asset/Sprite.h"
#include "Asset/Text.h"

#include "Core/RenderWindow.h"

RenderWindow*		InputManager::renderWindow		= nullptr;
bool				InputManager::pressInhibited	= false;
bool				InputManager::clickInhibited	= false;

bool InputManager::initialize(class RenderWindow& renderWindow)
{
	attachRenderWindow(renderWindow);

	return true;
}

void InputManager::update()
{
	//
}

void InputManager::terminate()
{
	detachRenderWindow();
}

void InputManager::handle(const sf::Event::KeyEvent keyEvent, bool pressed)
{
	if (renderWindow)
	{
		if (pressed && !pressInhibited)
		{
			switch (keyEvent.code)
			{
				case sf::Keyboard::Escape:
				{
					renderWindow->close();
				}
				break;
			}
		}
		else // released
		{
			pressInhibited = false;

			switch (keyEvent.code)
			{
				// to do
			}
		}
	}
	else
	{
		// to do debugger
	}
}

bool InputManager::isHoveringOver(RectangleShape* rect)
{
	auto mouse = sf::Mouse::getPosition(*renderWindow);

	if (mouse.x > ( (rect->getPosition().x) - (rect->getOrigin().x * rect->getScale().x) )												&&
		mouse.y > ( (rect->getPosition().y) - (rect->getOrigin().y * rect->getScale().y) )												&&
		mouse.x < ( (rect->getPosition().x) + (rect->getSize().x * rect->getScale().x) - (rect->getOrigin().x * rect->getScale().x) )	&&
		mouse.y < ( (rect->getPosition().y) + (rect->getSize().y * rect->getScale().y) - (rect->getOrigin().y * rect->getScale().y) )	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::isLeftClickingOn(RectangleShape* rect)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)	&& isHoveringOver(rect))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::isRightClickingOn(RectangleShape* rect)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && isHoveringOver(rect))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::isMiddleClickingOn(RectangleShape* rect)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && isHoveringOver(rect))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void InputManager::attachRenderWindow(class RenderWindow& renderWindow)
{
	InputManager::renderWindow = &renderWindow;
}

void InputManager::detachRenderWindow()
{
	renderWindow = nullptr;
}
