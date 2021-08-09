#include "Manager/StateManager.h"
#include "Core/Connection.h"
#include "Core/RenderWindow.h"

RenderWindow*		StateManager::renderWindow		= nullptr;
std::vector<State*>	StateManager::states			= std::vector<State*>();
size_t				StateManager::activeStateIndex	= 0;

bool StateManager::initialize(class RenderWindow& renderWindow)
{
	attachRenderWindow(renderWindow);

	return true;
}

void StateManager::update()
{
	for (auto state : states)
	{
		if (state->isActive())
		{
			switch (state->getStage())
			{
				case STATE_STAGE::CREATE:
				{
					state->create();
					state->setStage(STATE_STAGE::SETUP);
				}
				break;
				
				case STATE_STAGE::SETUP: // 1 of 3 STATE_STAGE's that need manual modification to get to next stage in derived states
				{
					state->setup();
					state->setStage(STATE_STAGE::UPDATE);
				}
				break;
				
				case STATE_STAGE::UPDATE: // 1 of 3 STATE_STAGE's that need manual modification to get to next stage in derived states
				{
					state->update();
				}
				break;
				
				case STATE_STAGE::RESOLVE: // 1 of 3 STATE_STAGE's that need manual modification to get to next stage in derived states
				{
					state->resolve();
					state->setStage(STATE_STAGE::DESRTOY);
				}
				break;
				
				case STATE_STAGE::DESRTOY:
				{
					state->destroy();
					state->setActive(false);
					state->setStage(STATE_STAGE::CREATE);
				}
				break;
			}
		}
	}
}

void StateManager::terminate()
{
	for (auto state : states)
	{
		delete state;
	}

	states.clear();

	detachRenderWindow();
}

void StateManager::createState(State* state)
{
	states.push_back(state);
	state->attachRenderWindow(*renderWindow);
}

size_t StateManager::getStateCount()
{
	return states.size();
}

State* StateManager::getState(size_t stateIndex)
{
	return states[stateIndex];
}

State* StateManager::getState(const std::string& id)
{
	for (auto state : states)
	{
		if (state->getID() == id)
		{
			return state;
		}
	}
	
	return nullptr; // debug to do
}

State* StateManager::getActiveState()
{
	return states[activeStateIndex];
}

void StateManager::setActiveState(size_t stateIndex)
{
	getActiveState()->setActive(false);
	states[stateIndex]->setActive(true);
	activeStateIndex = stateIndex;
}

void StateManager::setActiveState(const std::string& id)
{
	bool found = false;

	for (size_t i = 0; i < states.size(); i++)
	{
		if (states[i]->getID() == id)
		{
			getActiveState()->setActive(false);
			states[i]->setActive(true);
			bool found = true;
		}
	}

	if (!found)
	{
		// debug to do
	}
}

void StateManager::destroyState(size_t stateIndex)
{
	if (stateIndex >= 0 && stateIndex < states.size())
	{
		states[stateIndex]->detachRenderWindow();
		delete states[stateIndex];
		states.erase(states.begin() + stateIndex);
	}
	else
	{
		// debug to do
	}
}

void StateManager::destroyState(const std::string& id)
{
	for (size_t i = 0; i < states.size(); i++)
	{
		if (states[i]->getID() == id)
		{
			delete states[i];
			states.erase(states.begin() + i);
		}
	}
}

void StateManager::destroyStates()
{
	for (auto state : states)
	{
		delete state;
	}

	states.clear();
}

void StateManager::attachRenderWindow(RenderWindow& renderWindow)
{
	StateManager::renderWindow = &renderWindow;
}

void StateManager::detachRenderWindow()
{
	renderWindow = nullptr;
}