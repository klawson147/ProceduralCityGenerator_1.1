#pragma once
#include <vector>
#include <memory>
#include "IState.h"


class StateManager
{
public:
	StateManager();
	~StateManager();

	void ChangeState(std::shared_ptr<IState> state);
	void PushState(std::shared_ptr<IState> state);
	void PopState();
	void Clear();

	std::shared_ptr<IState> GetCurrentState();

private:
	std::vector<std::shared_ptr<IState>> m_states;
};
