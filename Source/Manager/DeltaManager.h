#ifndef DELTA_MANAGER_H
#define DELTA_MANAGER_H

#include "Core/Component.h"

class DeltaManager : public Singleton::NonInstantiable
{
public:

	static bool initialize();
	static void update();
	static void terminate();

public:

	static sf::Time getDeltaTime();
	static sf::Time getElapsed();

private:

	static sf::Clock	clock;
	static sf::Time		deltaTime;
	static sf::Time		elapsed;

};

using dm = DeltaManager;

#endif