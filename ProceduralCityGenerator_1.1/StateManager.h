#pragma once

#include <vector>
#include "IState.h"
#include "MainMenuState.h"
#include "ResourceHolder.h"

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

	const ResourceHolder& getResources() const;

private:
	std::vector<IState*> m_states;

	ResourceHolder m_resources;
};

