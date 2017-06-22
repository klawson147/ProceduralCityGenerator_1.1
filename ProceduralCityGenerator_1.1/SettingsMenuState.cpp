#include "SettingsMenuState.h"

SettingsMenuState::SettingsMenuState(StateManager* stateManager) : IState(stateManager)
{
}

SettingsMenuState::~SettingsMenuState()
{
}

void SettingsMenuState::Init()
{
	m_buttons.clear();
	m_background.setScale(1, 1);

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
		<CycleButton>(
		m_p_stateManager,
		CycleOptions::Resolution,
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 1, DisplayWindow::getSize().y / 1.25),
		"",
		""));

	m_buttons.push_back(
		std::make_shared
		<CycleButton>(
		m_p_stateManager,
		CycleOptions::AntiAlias,
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 2, DisplayWindow::getSize().y / 1.25),
		"",
		""));

	m_buttons.push_back(
		std::make_shared
		<BackButton>(
		m_p_stateManager,
		sf::Vector2f((DisplayWindow::getSize().x / 6) * 3, DisplayWindow::getSize().y / 1.25),
		"Back",
		""));
}
void SettingsMenuState::Cleanup()
{
}
void SettingsMenuState::Pause()
{
}
void SettingsMenuState::Resume()
{
}
void SettingsMenuState::GetEvents()
{
	sf::Event event;
	sf::RenderWindow* rw = DisplayWindow::getRenderWindow();
	bool needRefresh = false;

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
					needRefresh = true;
					i->get()->Click();
					
				}
			}
		}
	}
	if (needRefresh)
		Init();
}

void SettingsMenuState::Update()
{
}

void SettingsMenuState::Display()
{
	DisplayWindow::Draw(m_background);

	for (auto i = m_buttons.begin(); i != m_buttons.end(); i++)
	{
		i->get()->Display();
	}
}