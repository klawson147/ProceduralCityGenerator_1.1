#pragma once
#include "IState.h"
#include "IButton.h"

#include "MainMenuState.h"

#include "UserFields.h"
#include "BackButton.h"
#include "TextFieldButton.h"
#include "DirectionButton.h"

class OptionsMenuState :
	public IState
{
public:
	OptionsMenuState(StateManager*);
	~OptionsMenuState();

	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void GetEvents();
	void Update();
	void Display();

private:
	sf::Sprite								m_background;
	std::vector<std::shared_ptr<IButton>>	m_buttons;
	std::vector<std::tuple<UserFields, 
		std::string, 
		int, 
		int, 
		int>> m_defaultButtonValues;

private:
	void createButtons();

};

