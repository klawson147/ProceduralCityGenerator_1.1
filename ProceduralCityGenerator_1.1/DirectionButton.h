#pragma once
#include "IButton.h"
#include "IState.h"
#include <memory>

class DirectionButton :
	public IButton
{
public:
	DirectionButton(StateManager*	stateManager,
		std::shared_ptr<IState>		state,
		sf::Vector2f				position,
		const std::string			text,
		const std::string			textUpper);
	~DirectionButton();

	void Click();

private:
	StateManager*			m_p_stateManager;
	std::shared_ptr<IState> m_changeableState;

private:

};
