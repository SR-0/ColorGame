#include "Core/Engine.h"

// core includes
#include "Core/RenderWindow.h"

// manager includes
#include "Manager/DeltaManager.h"
#include "Manager/EventManager.h"
#include "Manager/InputManager.h"
#include "Manager/ConnectionManager.h"
#include "Manager/StateManager.h"
#include "Manager/FileManager.h"

// utility includes
#include "Utility/ColorConverter.h"
#include "Utility/RandomNumberGenerator.h"

#pragma region INCLUDE STATES HERE FOR NOW

// state includes
#include "State/StateTest1.h"
#include "State/StateTest2.h"
#include "State/StateTest3.h"
#include "State/StateTest4.h"

#pragma endregion

// static defines
RenderWindow* Engine::renderWindow;

bool Engine::initialize(int argc, char** argv)
{
	// move to parameters soon
	auto videoMode		= sf::VideoMode(1280, 720);
	auto title			= sf::String("Untitled");
	auto style			= sf::Uint32(sf::Style::Default);
	auto settings		= sf::ContextSettings();
	auto framerateLimit	= sf::Uint8(60);
	auto clearColor		= sf::Color(sf::Color::Black);

	// main render window initialization
	renderWindow = new RenderWindow
	(
		videoMode,
		title,
		style,
		settings,
		framerateLimit, 
		clearColor
	);

	// RandomNumberGenerator initialization
	rng::seed();

	// manager initialization checks
	if (!dm::initialize())				return false;
	if (!em::initialize(*renderWindow))	return false;
	if (!im::initialize(*renderWindow))	return false;
	if (!cm::initialize(*renderWindow))	return false;
	if (!sm::initialize(*renderWindow))	return false;
	if (!fm::initialize())				return false;

#pragma region TEST HERE FOR NOW

	/*
	
		to add more states, simply create a new class
		(preferably in the "State" folder) and derive
		it from base "State" class. You will have to
		override the 5 stages explained in State.h
		at beginning of header
	
	*/

	// add/create states to/for StateManager
	sm::createState(new StateTest1);
	sm::createState(new StateTest2);
	sm::createState(new StateTest3);
	sm::createState(new StateTest4);

	// set StateManager active state - switch this to desired active state via state index or ID
	sm::setActiveState("StateTest4");

#pragma endregion

	// all is good
	return true;
}

bool Engine::isRunning()
{
	// good enough check for now
	return renderWindow->isOpen();
}

void Engine::update()
{
	// update all managers
	dm::update();
	em::update();
	im::update();
	cm::update();
	sm::update();
	fm::update();
}

void Engine::render()
{
	// clear frame
	renderWindow->clear(sf::Color::Black);

	// draw frame
	for (size_t i = 0; i < sm::getStateCount(); i++)
	{
		if (sm::getState(i)->isActive() && sm::getState(i)->getStage() == STATE_STAGE::UPDATE)
		{
			renderWindow->draw(sm::getState(i));
		}
	}

	// display frame
	renderWindow->display();
}

void Engine::terminate()
{
	// terminate all managers
	fm::terminate();
	sm::terminate();
	cm::terminate();
	im::terminate();
	em::terminate();
	dm::terminate();

	// delete main render window
	delete renderWindow;
}
