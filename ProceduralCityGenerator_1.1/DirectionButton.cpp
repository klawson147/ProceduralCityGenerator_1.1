#include "DirectionButton.h"


DirectionButton::DirectionButton(
	StateManager* stateManager,
	std::shared_ptr<IState>	state,
	sf::Vector2f position,
	const std::string text,
	const std::string textUpper) : IButton(position, text, textUpper)
{
	m_p_stateManager = stateManager;
}


DirectionButton::~DirectionButton()
{
}

void DirectionButton::Update()
{
	m_p_stateManager->ChangeState(m_changeableState);
}

