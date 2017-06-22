#include "MainMenuState.h"

MainMenuState::MainMenuState(StateManager* stateManager) : IState(stateManager)
{
}

void MainMenuState::Init()
{
	m_background.setScale(1, 1);
	m_buttons.clear();

	m_background.setTexture(ResourceHolder::get().getTexture(TextureName::menu_background));

	m_background.scale(
		DisplayWindow::getSize().x / m_background.getLocalBounds().width,
		DisplayWindow::getSize().y / m_background.getLocalBounds().height);

	m_background.setPosition(
		DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_left,
		sf::Vector2f(0, 0),
		sf::Vector2f(-20, -20)));

	m_buttons.push_back(
		std::make_shared
		<DirectionButton>(
		m_p_stateManager,
		std::make_shared<SplashScreenState>(m_p_stateManager),
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 1, DisplayWindow::getSize().y / 1.25),
		"Quick Start",
		""));

	m_buttons.push_back(
		std::make_shared
		<DirectionButton>(
		m_p_stateManager,
		std::make_shared<OptionsMenuState>(m_p_stateManager),
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 2, DisplayWindow::getSize().y / 1.25),
		"Sim Options",
		""));

	m_buttons.push_back(
		std::make_shared
		<DirectionButton>(
		m_p_stateManager,
		std::make_shared<SettingsMenuState>(m_p_stateManager),
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 3, DisplayWindow::getSize().y / 1.25),
		"Settings",
		""));

	m_buttons.push_back(
		std::make_shared
		<ExitButton>(
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 4, DisplayWindow::getSize().y / 1.25),
		"Exit",
		""));
}

void MainMenuState::Cleanup()
{
}

void MainMenuState::Pause()
{
}

void MainMenuState::Resume()
{
	Init();
}

void MainMenuState::GetEvents()
{
	sf::Event event;
	sf::RenderWindow* rw = DisplayWindow::getRenderWindow();

	while (rw->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			DisplayWindow::Close();
			break;

		case sf::Event::MouseButtonPressed:
			for (auto i = m_buttons.begin(); i != m_buttons.end(); i++)
			{
				if (i->get()->Contains(sf::Mouse::getPosition(*rw)))
				{
					i->get()->Click();
				}
			}
			break;
		}
	}
}

void MainMenuState::Update()
{
}

void MainMenuState::Display()
{
	DisplayWindow::Draw(m_background);

	for (auto i = m_buttons.begin(); i != m_buttons.end(); i++)
	{
		i->get()->Display();
	}
}