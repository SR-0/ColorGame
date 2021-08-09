#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Core/Component.h"

class EventManager : public Singleton::NonInstantiable
{
public:

	static bool initialize(class RenderWindow& renderWindow);
	static void update();
	static void terminate();

public:

	static void attachRenderWindow(class RenderWindow& renderWindow);
	static void detachRenderWindow();

private:

	static class RenderWindow* renderWindow;

};

using em = EventManager;

#endif