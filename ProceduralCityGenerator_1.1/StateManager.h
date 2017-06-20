#pragma once

#include <vector>
#include "IState.h"
#include "MainMenuState.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	void ChangeState(IState* state);
	void PushState(IState* state);
	void PopState();
	void Clear();

	IState* GetCurrentState();



private:
	std::vector<IState*> m_states;
};

