#ifndef STATE_TEST_2_H
#define STATE_TEST_2_H

#include "Core/State.h"

/*
	this is an expansion of TestState1:

		1.) adds soundBuffer for sound

		2.) adds sound for "ok" sound effect

		3.) adds music track for background music

	- end of state
*/

class StateTest2 : public State
{
public:

	StateTest2() : State("StateTest2") {}

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
	RectangleShape* rect;

};

#endif