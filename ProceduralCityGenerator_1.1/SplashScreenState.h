#include "IState.h"
#pragma once

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


	SplashScreenState();
	~SplashScreenState();

private:
	sf::Text	m_title_main;
	sf::Text	m_title_secondary;

	sf::Sprite	m_background;
	sf::Sprite	m_logo;
};

