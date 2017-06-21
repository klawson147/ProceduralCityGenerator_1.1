#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(StateManager* stateManager) : IState(stateManager)
{

}

void SplashScreenState::Init()
{
	m_title_main.setFont(m_s_c_resourceHolder.fonts.get(FontName::sf_atarian_system));
	m_title_main.setCharacterSize(62);
	m_title_main.setColor(sf::Color(255, 255, 255, 255));
	m_title_main.setString("Procedural City Generator");
	m_title_main.setPosition(300, 300);



	m_title_secondary.setFont(m_s_c_resourceHolder.fonts.get(FontName::sf_atarian_system));

	m_logo.setTexture(m_s_c_resourceHolder.textures.get(TextureName::sfml_logo));
	m_background.setTexture(m_s_c_resourceHolder.textures.get(TextureName::skyline1920));
}

void SplashScreenState::Cleanup()
{
}

void SplashScreenState::Pause()
{
}

void SplashScreenState::Resume()
{
}

void SplashScreenState::GetEvents()
{
}

void SplashScreenState::Update()
{

}

void SplashScreenState::Display()
{
	DisplayWindow::Draw(m_title_main);
	//DisplayWindow::Draw(m_title_secondary);
	//DisplayWindow::Draw(m_logo);
	//DisplayWindow::Draw(m_background);
}