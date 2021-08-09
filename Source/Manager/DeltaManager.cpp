#include "Manager/DeltaManager.h"

sf::Clock	DeltaManager::clock;
sf::Time	DeltaManager::deltaTime;
sf::Time	DeltaManager::elapsed;

bool DeltaManager::initialize()
{
	return true;
}

void DeltaManager::update()
{
	deltaTime = clock.restart();
	elapsed += deltaTime;
}

void DeltaManager::terminate()
{
	//
}

sf::Time DeltaManager::getDeltaTime()
{
	return deltaTime;
}

sf::Time DeltaManager::getElapsed()
{
	return elapsed;
}
