#ifndef ENGINE_H
#define ENGINE_H

#include "Core/Component.h"

class Engine : public Singleton::NonInstantiable
{
public:

	static bool initialize(int argc, char** argv);
	static bool isRunning();
	static void update();
	static void render();
	static void terminate();

public:

	static class RenderWindow* renderWindow;

};

using engine = Engine;

#endif