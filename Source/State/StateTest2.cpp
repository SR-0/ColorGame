#include "State/StateTest2.h"

void StateTest2::create()
{
	// initialize/create/allocate all assets (IDs optional)
	soundBuffer	= createSoundBuffer("SoundBufferOK");
	sound		= createSound("SoundOK");
	track		= createMusic("MusicInnerLight");
	rect		= createRectangleShape("RectangleShapeBox");
}

void StateTest2::setup()
{
	// sound buffers
	soundBuffer->loadFromFile("../../../Resource/Sounds/ok.wav");
	
	// sounds
	sound->setBuffer(*soundBuffer);
	
	// music
	track->openFromFile("Music/inner_light.wav");
	track->play();

	// shapes
	rect->setSize(100, 100);
	rect->setOrigin(rect->getSize().x / 2, rect->getSize().y / 2);
	rect->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);
	rect->setFillColor(sf::Color(0, 0, 255, 0));
}

void StateTest2::update()
{
	auto deltaTime = dm::getDeltaTime().asMilliseconds();

	// if rect is not opaque, keep fading rect in
	if (!rect->isOpaque())
	{
		rect->fadeIn(0.2f * deltaTime);
	}
	else
	{
		// change color and play sound if clicking on rect
		if (im::isLeftClickingOn(rect))
		{
			if (!sound->isActive())
			{
				sound->play();
				sound->setActive(true);
			}

			rect->setFillColor(sf::Color::Green);
		}
		// change to original color
		else
		{
			rect->setFillColor(sf::Color::Blue);
			sound->setActive(false);
		}
	}

	// end state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		sound->play();
		setStage(STATE_STAGE::RESOLVE);
	}
}

void StateTest2::destroy()
{
	destroyAll(); // <- destroys any and all state asset use with create functions
}