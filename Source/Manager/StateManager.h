#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "Core/Component.h"
#include "Core/State.h"

/*

	major debugging and commentation comming soon...

*/

class StateManager : public Singleton::NonInstantiable
{
public:

	static bool initialize(class RenderWindow& renderWindow);
	static void update();
	static void terminate();

public:

	static void			createState(class State* state);
	static size_t		getStateCount();
	static class State*	getState(size_t stateIndex);
	static class State*	getState(const std::string& id);
	static class State* getActiveState();
	static void			setActiveState(size_t stateIndex);
	static void			setActiveState(const std::string& id);
	static void			destroyState(size_t stateIndex);
	static void			destroyState(const std::string& id);
	static void			destroyStates();

public:

	static void attachRenderWindow(class RenderWindow& renderWindow);
	static void detachRenderWindow();

private:

	static class RenderWindow*			renderWindow;
	static std::vector<class State*>	states;
	static size_t						activeStateIndex;

};

using sm = StateManager;

#endif