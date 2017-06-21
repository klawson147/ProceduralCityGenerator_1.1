#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(StateManager* stateManager) : IState(stateManager)
{
}

void SplashScreenState::Init()
{
	m_title_main.setFont(m_s_c_resourceHolder.fonts.get(FontName::sf_atarian_system));
	m_title_main.setCharacterSize(62);
	m_title_main.setColor(sf::Color(0, 0, 0, 255));
	m_title_main.setString("Procedural City Generator");

	sf::Vector2f pos = DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_center,
		sf::Vector2u(
		m_title_main.getGlobalBounds().width,
		m_title_main.getGlobalBounds().height),
		sf::Vector2f(0, 0));

	m_title_main.setPosition(pos);

	m_title_secondary.setFont(m_s_c_resourceHolder.fonts.get(FontName::sf_atarian_system));
	m_title_secondary.setCharacterSize(36);
	m_title_secondary.setColor(sf::Color(0, 0, 0, 255));
	m_title_secondary.setString("Created Using");

	pos = DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_center,
		sf::Vector2u(
		m_title_secondary.getGlobalBounds().width,
		m_title_secondary.getGlobalBounds().height),
		sf::Vector2f(0, 125));

	m_title_secondary.setPosition(pos);

	m_logo.setTexture(m_s_c_resourceHolder.textures.get(TextureName::sfml_logo_small));
	m_logo.setPosition(
		DisplayWindow::getRelativePosition(
		DisplayWindowPosition::center_center,
		sf::Vector2u(
		m_logo.getLocalBounds().width,
		m_logo.getLocalBounds().height),
		sf::Vector2f(0, -50)));

		m_background.setTexture(m_s_c_resourceHolder.textures.get(TextureName::skyline1920));
		m_background.setPosition(
			DisplayWindow::getRelativePosition(
			DisplayWindowPosition::bottom_left,
			sf::Vector2u(
			m_background.getLocalBounds().width,
			m_background.getLocalBounds().height),
			sf::Vector2f(-20, 20)));
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
	DisplayWindow::Draw(m_title_secondary);
	DisplayWindow::Draw(m_logo);
	DisplayWindow::Draw(m_background);
}