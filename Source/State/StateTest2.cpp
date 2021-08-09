#include "State/StateTest2.h"

void StateTest2::create()
{
	// initialize/create/allocate all assets (IDs optional)
	soundBuffer	= createSoundBuffer("SoundBufferOK");
	sound		= createSound("SoundOK");
	track		= createMusic("MusicInnerLight");
	box			= createRectangleShape("box");
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
	box->setSize(100, 100);
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);
	box->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);
	box->setFillColor(sf::Color(0, 0, 255, 0));
}

void StateTest2::update()
{
	auto deltaTime = dm::getDeltaTime().asMilliseconds();

	// if box is not opaque, keep fading box in
	if (!box->isOpaque())
	{
		box->fadeIn(0.2f * deltaTime);
	}
	else
	{
		// change color and play sound if clicking on box
		if (im::isLeftClickingOn(box))
		{
			if (!sound->isActive())
			{
				sound->play();
				sound->setActive(true);
			}

			box->setFillColor(sf::Color::Green);
		}
		// change to original color
		else
		{
			box->setFillColor(sf::Color::Blue);
			sound->setActive(false);
		}
	}

	// end state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		sound->play();
		sound->setActive(true);
		setStage(STATE_STAGE::RESOLVE);
	}
}

void StateTest2::destroy()
{
	destroyAll(); // <- destroys any and all state asset use with create functions
}