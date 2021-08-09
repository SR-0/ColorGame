#include "State/StateTest3.h"

void StateTest3::create()
{
	// initialize/create/allocate all assets (IDs optional)
	soundBuffer	= createSoundBuffer("SoundBufferOK");
	sound		= createSound("SoundOK");
	track		= createMusic("MusicInnerLight");
	font		= createFont("FontDefault");
	box			= createRectangleShape("RectangleShapeBox");
	text		= createText("TextMessage");
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

	// shapes (rect) - NOTE: fill color is automatically white so I took the "setFillColor" away. **White is the color needed for textures**
	box->setSize(100, 100);
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);
	box->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);

	// texts
	text->setFont(*font);
	text->setPosition(300, 250);
	text->setString("left click or move (W, A, S, D) the box");
}

void StateTest3::update()
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

	// crude movement example
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		box->move(sf::Vector2f(0, -0.3f * deltaTime));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		box->move(sf::Vector2f(-0.3f * deltaTime, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		box->move(sf::Vector2f(0, 0.3f * deltaTime));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		box->move(sf::Vector2f(0.3f * deltaTime, 0.));
	}

	// end state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		sound->play();
		sound->setActive(true);
		setStage(STATE_STAGE::RESOLVE);
	}
}

void StateTest3::destroy()
{
	destroyAll(); // <- destroys any and all state asset use with create functions
}