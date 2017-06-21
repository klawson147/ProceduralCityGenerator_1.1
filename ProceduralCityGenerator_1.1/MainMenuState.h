#pragma once
#include "IState.h"
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
	sf::Sprite	m_background;
};
