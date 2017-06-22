#pragma once
#include "IState.h"
#include "IButton.h"
#include <memory>

#include "BackButton.h"
#include "CycleButton.h"



class SettingsMenuState :
	public IState
{
public:
	SettingsMenuState(StateManager*);
	~SettingsMenuState();



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

