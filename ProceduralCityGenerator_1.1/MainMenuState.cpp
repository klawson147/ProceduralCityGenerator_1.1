#include "MainMenuState.h"

MainMenuState::MainMenuState(StateManager* stateManager) : IState(stateManager)
{
}

void MainMenuState::Init()
{
	m_background.setTexture(ResourceHolder::get().getTexture(TextureName::menu_background));

	m_background.scale(
		DisplayWindow::getSize().x / m_background.getLocalBounds().width,
		DisplayWindow::getSize().y / m_background.getLocalBounds().height);

	m_background.setPosition(
		DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_left,
		sf::Vector2f(0, 0),
		sf::Vector2f(-20, -20)));
}

void MainMenuState::Cleanup()
{
}

void MainMenuState::Pause()
{
}

void MainMenuState::Resume()
{
}

void MainMenuState::GetEvents()
{
}

void MainMenuState::Update()
{
}

void MainMenuState::Display()
{
	DisplayWindow::Draw(m_background);
}