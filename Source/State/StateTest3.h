#ifndef STATE_TEST_3_H
#define STATE_TEST_3_H

#include "Core/State.h"

/*
	this is an expansion of TestState2:

		1.) adds font for text

		2.) add text and set font to newly added font and display over box

		3.) add controls to move rect around

		4.) various little things

	- end of state
*/

class StateTest3 : public State
{
public:

	StateTest3() : State("StateTest3") {}

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
	RectangleShape* box;
	Text*			text;

};

#endif