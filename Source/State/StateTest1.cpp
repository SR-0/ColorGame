#include "State/StateTest1.h"

void StateTest1::create()
{
	rect = createRectangleShape(); // <- automatically adds to managable shape container
}

void StateTest1::setup()
{
	rect->setSize(100, 100);
	rect->setOrigin(rect->getSize().x / 2, rect->getSize().y / 2);
	rect->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);
	rect->setFillColor(sf::Color(0, 0, 255, 0));
}

void StateTest1::update()
{
	if (!rect->isOpaque())
	{
		rect->fadeIn(0.2f * dm::getDeltaTime().asMilliseconds());
	}

	if (im::isLeftClickingOn(rect))
	{
		rect->setFillColor(sf::Color::Green);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		setStage(STATE_STAGE::RESOLVE);
	}
}

void StateTest1::destroy()
{
	destroyShapes(); // <- destroys any and all shapes use with create functions
}