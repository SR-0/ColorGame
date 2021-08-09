#ifndef STATE_TEST_1_H
#define STATE_TEST_1_H

#include "Core/State.h"

/*
	this state is short and simple:

		1.) rect fades in

		2.) if you left-click on rect, it will turn green

		3.) if you hit backspace, it resolves and then ends
		the state (stateless RenderWindow a.k.a. blank
		RenderWindow)

	- end of state
*/

class StateTest1 : public State
{
public:

	StateTest1() : State("StateTest1") {}

public:

	virtual void create() override final;
	virtual void setup() override final;
	virtual void update() override final;
	virtual void resolve() override final {}
	virtual void destroy() override final;

public:

	RectangleShape* rect;

};

#endif