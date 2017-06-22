#pragma once
#include "IButton.h"
#include "DisplayWindow.h"

enum CycleOptions
{
	Resolution,
	AntiAlias
};

enum ResolutionOptions
{
	
	r720,
	r768,
	r900,
	r1080
};

enum AntiAliasOptions
{
	a0,
	a2,
	a4,
	a8
};

class CycleButton :
	public IButton
{
public:
	CycleButton(StateManager* sm,
		CycleOptions option,
		sf::Vector2f	position,
		const std::string	text,
		const std::string	textUpper);
	~CycleButton();

	void Click();

private:
	StateManager*		m_p_stateManager;
	CycleOptions		m_option;
	int					m_selection;
};
