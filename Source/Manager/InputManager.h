#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Core/Component.h"

class InputManager : public Singleton::NonInstantiable
{
public:

	static bool initialize(class RenderWindow& renderWindow);
	static void update();
	static void terminate();

public:

	static void handle(const sf::Event::KeyEvent keyEvent, bool pressed);

public:

	static bool isHoveringOver(class RectangleShape* rect);
	static bool isLeftClickingOn(class RectangleShape* rect);
	static bool isRightClickingOn(class RectangleShape* rect);
	static bool isMiddleClickingOn(class RectangleShape* rect);

public:

	static void attachRenderWindow(class RenderWindow& renderWindow);
	static void detachRenderWindow();

private:

	static class RenderWindow*	renderWindow;
	static bool					pressInhibited;
	static bool					clickInhibited;

};

using im = InputManager;

#endif