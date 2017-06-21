#pragma once
#include <iostream>
#include "ResourceHolder.h"
#include "DisplayWindow.h"

class StateManager;

class IState
{
public:

	IState(StateManager*);

	// Executed at the beginning of each state
	virtual void Init() = 0;

	// Occurs when the state is left
	virtual void Cleanup() = 0;

	// Execute code to pause a state
	virtual void Pause() = 0;

	// Execute code to resume a state
	virtual void Resume() = 0;

	// Recieves and process input
	virtual void GetEvents() = 0;

	// Occurs each frame/timestep
	virtual void Update() = 0;

	// Draw this state
	virtual void Display() = 0;

protected:
	StateManager* m_p_stateManager;
};
