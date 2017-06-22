#include "BackButton.h"


BackButton::BackButton(StateManager* sm, sf::Vector2f	position, const std::string	text, const std::string	textUpper) : IButton(position, text, textUpper)
{
	m_p_stateManager = sm;
}


BackButton::~BackButton()
{
}


void BackButton::Click()
{
	m_p_stateManager->PopState();
}