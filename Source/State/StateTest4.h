#ifndef STATE_TEST_4_H
#define STATE_TEST_4_H

#include "Core/State.h"

/*
	this is an expansion of TestState3:

		1.) adds 2 textures for box and new background RectangleShapes (any shape can have a texture)

		2.) adds 2 more RectangleShapes for background and splash screen

		3.) adds 2 layers to for this state's RenderWindow's renderLayerMax (3 total)

		4.) set renderLayers for RectangleShapes amd Texts (background = 1, box = 2, splash = 3, text = 2)

		4.) fade out splash before start

		5.) fade in splash before end

		6.) clean up and various little things

	- end of state
*/

class StateTest4 : public State
{
public:

	StateTest4() : State("StateTest4") {}

public:

	virtual void create() override final;
	virtual void setup() override final;
	virtual void update() override final;
	virtual void resolve() override final {}
	virtual void destroy() override final;

public:

	SoundBuffer*	soundBuffer;
	Sound*			sound;
	Music*			track;
	Font*			font;
	Texture*		textureBackground;
	Texture*		textureBox;
	RectangleShape*	background;
	RectangleShape* box;
	RectangleShape*	splash;
	Text*			text;
	bool			ending;

};

#endif