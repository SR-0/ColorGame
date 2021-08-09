#include "Core/Engine.h"

#include "Core/RenderWindow.h"

#include "Manager/DeltaManager.h"
#include "Manager/EventManager.h"
#include "Manager/InputManager.h"
#include "Manager/ConnectionManager.h"
#include "Manager/StateManager.h"
#include "Manager/FileManager.h"

#include "Utility/RandomNumberGenerator.h"

#include "State/StateTest1.h"
#include "State/StateTest2.h"
#include "State/StateTest3.h"

// test
#include "Asset/SoundBuffer.h"
#include "Asset/Sound.h"

RenderWindow* Engine::renderWindow;

bool Engine::initialize(int argc, char** argv)
{
	// move to parameters soon
	auto videoMode		= sf::VideoMode(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
	auto title			= sf::String("Untitled");
	auto style			= sf::Uint32(sf::Style::Default);
	auto settings		= sf::ContextSettings();
	auto framerateLimit	= sf::Uint8(60);
	auto clearColor		= sf::Color(sf::Color::Black);

	renderWindow = new RenderWindow
	(
		videoMode,
		title,
		style,
		settings,
		framerateLimit, 
		clearColor
	);

	rng::seed();

	if (!dm::initialize())				return false;
	if (!em::initialize(*renderWindow))	return false;
	if (!im::initialize(*renderWindow))	return false;
	if (!cm::initialize(*renderWindow))	return false;
	if (!sm::initialize(*renderWindow))	return false;
	if (!fm::initialize())				return false;

#pragma region TEST HERE FOR NOW

	/*
	
		to add more states, simple create a new class
		(preferably in the "State" folder) and derive
		is from base "State" class. You will have to
		override the 5 stages explained in State.h
		at beginning of header
	
	*/
	sm::createState(new StateTest1);
	sm::createState(new StateTest2);
	sm::createState(new StateTest3);

	sm::setActiveState("StateTest3"); // switch this to desired active state via state index or ID

#pragma endregion

	return true;
}

bool Engine::isRunning()
{
	return renderWindow->isOpen();
}

void Engine::update()
{
	dm::update();
	em::update();
	im::update();
	cm::update();
	sm::update();
	fm::update();
}

void Engine::render()
{
	renderWindow->clear(sf::Color::Black);

	for (size_t i = 0; i < sm::getStateCount(); i++)
	{
		if (sm::getState(i)->isActive() && sm::getState(i)->getStage() == STATE_STAGE::UPDATE)
		{
			renderWindow->draw(sm::getState(i));
		}
	}

	renderWindow->display();
}

void Engine::terminate()
{
	dm::terminate();
	em::terminate();
	im::terminate();
	cm::terminate();
	sm::terminate();
	fm::terminate();

	delete renderWindow;
}
