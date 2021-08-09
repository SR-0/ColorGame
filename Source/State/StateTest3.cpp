#include "State/StateTest3.h"

void StateTest3::create()
{
	// initialize/create/allocate all assets (IDs optional)
	soundBuffer	= createSoundBuffer("SoundBufferOK");
	sound		= createSound("SoundOK");
	track		= createMusic("MusicInnerLight");
	font		= createFont("FontDefault");
	rect		= createRectangleShape("RectangleShapeBox");
	text		= createText("TextClickTheBox");
}

void StateTest3::setup()
{
	// sound buffers
	soundBuffer->loadFromFile("Resources/Sounds/ok.wav");

	// sounds
	sound->setBuffer(*soundBuffer);

	// music
	track->openFromFile("Resources/Music/inner_light.wav");
	track->play();

	// fonts
	font->loadFromFile("Resources/Fonts/chess_type.ttf");

	// shapes
	rect->setSize(100, 100);
	rect->setOrigin(rect->getSize().x / 2, rect->getSize().y / 2);
	rect->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);
	rect->setFillColor(sf::Color(0, 0, 255, 0));
	
	// texts
	text->setFont(*font);
	//text->setOrigin(sf::Vector2f(text->getCharacterSize() / 2, text->getCharacterSize() / 2));
	text->setPosition(640, 400);
	text->setString("left click or move (W, A, S, D) the box");
}

void StateTest3::update()
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

	// crude movement example
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect->move(sf::Vector2f(0, -0.3f * deltaTime));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect->move(sf::Vector2f(-0.3f * deltaTime, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect->move(sf::Vector2f(0, 0.3f * deltaTime));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect->move(sf::Vector2f(0.3f * deltaTime, 0.));
	}

	// end state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		sound->play();
		setStage(STATE_STAGE::RESOLVE);
	}
}

void StateTest3::destroy()
{
	destroyAll(); // <- destroys any and all state asset use with create functions
}