#pragma once
#include "IButton.h"
#include "StateManager.h"

class BackButton :
	public IButton
{
public:
	BackButton(StateManager* sm, sf::Vector2f	position, const std::string	text, const std::string	textUpper);
	~BackButton();

	void Click();

private:
	StateManager* m_p_stateManager;
};

