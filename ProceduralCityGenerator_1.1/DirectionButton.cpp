#include "DirectionButton.h"


DirectionButton::DirectionButton(
	StateManager* stateManager,
	std::shared_ptr<IState>	state,
	sf::Vector2f position,
	const std::string text,
	const std::string textUpper) : IButton(position, text, textUpper)
{
	m_p_stateManager = stateManager;
	m_changeableState = state;
}


DirectionButton::~DirectionButton()
{
}

void DirectionButton::Click()
{
	m_p_stateManager->ChangeState(m_changeableState);
}

