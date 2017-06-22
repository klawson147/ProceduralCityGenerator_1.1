#pragma once
#include "IState.h"
#include "DirectionButton.h"
#include "ExitButton.h"

#include "SplashScreenState.h"
#include "SettingsMenuState.h"
#include "OptionsMenuState.h"

class MainMenuState :
	public IState
{
public:

	MainMenuState(StateManager*);

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
};
