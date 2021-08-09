#include "State/StateTest4.h"

void StateTest4::create()
{
	// initialize/create/allocate all assets (IDs optional)
	soundBuffer			= createSoundBuffer("SoundBufferOK");
	sound				= createSound("SoundOK");
	track				= createMusic("MusicInnerLight");
	font				= createFont("FontDefault");
	textureBackground	= createTexture("TextureBackground");
	textureBox			= createTexture("TextureRect");
	background			= createRectangleShape("RectangleShapeBackground");
	box					= createRectangleShape("RectangleShapeBox");
	splash				= createRectangleShape("RectangleShapeSplash");
	text				= createText("TextMessage");
	ending				= false;
}

void StateTest4::setup()
{
	// render window setup - NOTE: default render layer max is 1
	getRenderWindow().setRenderLayerMax(3);

	// sound buffers
	soundBuffer->loadFromFile("Resources/Sounds/ok.wav");

	// sounds
	sound->setBuffer(*soundBuffer);

	// music
	track->openFromFile("Resources/Music/inner_light.wav");
	track->play();

	// fonts
	font->loadFromFile("Resources/Fonts/chess_type.ttf");

	// textures
	textureBackground->loadFromFile("Resources/Textures/background_1280x720.png");
	textureBox->loadFromFile("Resources/Textures/box.png");

	// shapes (background) - NOTE: I don't need to set render layer on this layer since the default is already 1, but I did anyway
	background->setSize(sf::Vector2f(textureBackground->getSize()));
	background->setTexture(textureBackground);
	background->setRenderLayer(1);

	// shapes (rect) - NOTE: fill color is automatically white so I took the "setFillColor" away. **White is the color needed for textures**
	box->setSize(sf::Vector2f(textureBox->getSize()));
	box->setTexture(textureBox);
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);
	box->setPosition(getRenderWindow().getSize().x / 2, getRenderWindow().getSize().y / 2);
	box->setScale(sf::Vector2f(.2f, .2f));
	box->setRenderLayer(2);

	// shapes (splash) - NOTE: I don't set origin or position for background or splash because (0, 0) is the default origin and position
	splash->setFillColor(sf::Color::Black);
	splash->setSize(sf::Vector2f(getRenderWindow().getSize()));
	splash->setRenderLayer(3);
	
	// texts
	text->setFont(*font);
	text->setPosition(300, 250);
	text->setString("left click or move (W, A, S, D) the box");
	text->setRenderLayer(2);
}

void StateTest4::update()
{
	auto deltaTime = dm::getDeltaTime().asMilliseconds();

	// if ending, prepare for RESOLVE/DESTROY stage transition
	if (ending)
	{
		/*
		
			fade out box, fade in splash, and set stage 
			to 'RESOLVE' - NOTE: RESOLVE stage automatically 
			transitions to DESTROY stage after completion

		*/

		// fade out rect
		if (!box->isTransparent())
		{
			box->fadeOut(0.2f * deltaTime);
		}
		// fade in splash
		else if (!splash->isOpaque())
		{
			splash->fadeIn(0.2f * deltaTime);
		}
		// set to RESOLVE stage
		else
		{
			setStage(STATE_STAGE::RESOLVE);
		}
	}
	// fade out splash
	else if (!splash->isTransparent())
	{
		splash->fadeOut(0.2f * deltaTime);
	}
	// fade in box
	else if (!box->isOpaque())
	{
		box->fadeIn(0.2f * deltaTime);
	}
	// main update block
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
			box->setFillColor(sf::Color::White); // changed from blue to white for texture visibility
			sound->setActive(false);
		}

		// move up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			box->move(sf::Vector2f(0, -0.3f * deltaTime));
		}
		// move left
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			box->move(sf::Vector2f(-0.3f * deltaTime, 0));
		}
		// move down
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			box->move(sf::Vector2f(0, 0.3f * deltaTime));
		}
		// move right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			box->move(sf::Vector2f(0.3f * deltaTime, 0.));
		}

		// end state
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			ending = true;
			sound->play();
			sound->setActive(true);
		}
	}
}

void StateTest4::destroy()
{
	destroyAll(); // <- destroys any and all state asset use with create functions
}
