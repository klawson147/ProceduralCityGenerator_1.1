#pragma once
#include "IState.h"
#include "StateManager.h"

class SplashScreenState :
	public IState
{
public:

	SplashScreenState(StateManager*);

	void Init();
	void Cleanup();
	void Pause();
	void Resume();
	void GetEvents();
	void Update();
	void Display();

private:
	sf::Text	m_title_main;
	sf::Text	m_title_secondary;

	sf::Sprite	m_background;
	sf::Sprite	m_logo;

	sf::Clock	m_splashClock;
};
