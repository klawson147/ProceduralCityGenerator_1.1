#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(StateManager* stateManager) : IState(stateManager)
{
}

// Refactor?
void SplashScreenState::Init()
{
	m_splashClock.restart();

	m_title_main.setFont(ResourceHolder::get().getFont(FontName::sf_atarian_system));
	m_title_main.setCharacterSize(62);
	m_title_main.setColor(sf::Color(0, 0, 0, 255));
	m_title_main.setString("Procedural City Generator");
	m_title_main.setPosition(DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_center,
		sf::Vector2f(
		m_title_main.getGlobalBounds().width,
		m_title_main.getGlobalBounds().height),
		sf::Vector2f(0, 0)));

	m_title_secondary.setFont(ResourceHolder::get().getFont(FontName::sf_atarian_system));
	m_title_secondary.setCharacterSize(36);
	m_title_secondary.setColor(sf::Color(0, 0, 0, 255));
	m_title_secondary.setString("Created Using");
	m_title_secondary.setPosition(DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_center,
		sf::Vector2f(
		m_title_secondary.getGlobalBounds().width,
		m_title_secondary.getGlobalBounds().height),
		sf::Vector2f(0, 125)));

	m_logo.setTexture(ResourceHolder::get().getTexture(TextureName::sfml_logo_small));
	m_logo.setPosition(
		DisplayWindow::getRelativePosition(
		DisplayWindowPosition::center_center,
		sf::Vector2f(
		m_logo.getLocalBounds().width,
		m_logo.getLocalBounds().height),
		sf::Vector2f(0, -50)));

	m_background.setTexture(ResourceHolder::get().getTexture(TextureName::skyline1920));
	m_background.scale(
		DisplayWindow::getSize().x / m_background.getLocalBounds().width,
		1);

	m_background.setPosition(
		DisplayWindow::getRelativePosition(
		DisplayWindowPosition::bottom_left,
		sf::Vector2f(
		m_background.getLocalBounds().width,
		m_background.getLocalBounds().height),
		sf::Vector2f(-20, 20)));
}

void SplashScreenState::Cleanup()
{
	return;
}

void SplashScreenState::Pause()
{
	return;
}

void SplashScreenState::Resume()
{
	return;
}

void SplashScreenState::GetEvents()
{
	return;
}

// Each update checks if time elapsed is greater than the amount of time splash screen should be displayed
void SplashScreenState::Update()
{
	if (m_splashClock.getElapsedTime().asSeconds() > WAIT_TIME_SECOND)
	{
		m_p_stateManager->PopState();
	}
}

void SplashScreenState::Display()
{
	DisplayWindow::Draw(m_title_main);
	DisplayWindow::Draw(m_title_secondary);
	DisplayWindow::Draw(m_logo);
	DisplayWindow::Draw(m_background);
}