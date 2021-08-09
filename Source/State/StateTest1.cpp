#include "State/StateTest1.h"

void StateTest1::create()
{
	box = createRectangleShape(); // <- automatically adds to managable shape container
}

void StateTest1::setup()
{
	box->setSize(100, 100);
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);
	box->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);
	box->setFillColor(sf::Color(0, 0, 255, 0));
}

void StateTest1::update()
{
	if (!box->isOpaque())
	{
		box->fadeIn(0.2f * dm::getDeltaTime().asMilliseconds());
	}

	if (im::isLeftClickingOn(box))
	{
		box->setFillColor(sf::Color::Green);
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