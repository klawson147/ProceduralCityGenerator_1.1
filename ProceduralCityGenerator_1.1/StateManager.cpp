#include "StateManager.h"


StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

// Remove all states
void StateManager::Clear()
{
	while (!m_states.empty())
	{
		m_states.back()->Cleanup();
		m_states.pop_back();
	}
}

// Remove current state and start new state
void StateManager::ChangeState(IState* state)
{
	if (!m_states.empty())
	{
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	m_states.push_back(state);
	m_states.back()->Init();
}

// Pause current state and start new state
void StateManager::PushState(IState* state)
{
	if (!m_states.empty())
	{
		m_states.back()->Pause();
		
	}

	m_states.push_back(state);
	m_states.back()->Init();
}

// Exit current state and resume previous state.
void StateManager::PopState()
{
	if (!m_states.empty())
	{
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	if (!m_states.empty())
	{
		m_states.back()->Resume();
	}
}

// Returns the current state
IState* StateManager::GetCurrentState()
{
	return m_states.back();
}