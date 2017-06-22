#include "SimulationState.h"


SimulationState::SimulationState(StateManager* stateManager) : IState(stateManager) 
{

	backGroundColor_ = sf::Color::White;

	pausedFont_.loadFromFile("resources/fonts/SF_Atarian_System.ttf");
	pausedText_.setFont(pausedFont_);
	pausedText_.setString("Paused");
	pausedText_.setCharacterSize(38);
	pausedText_.setPosition(10, 10);
	pausedText_.setColor(sf::Color(255 - backGroundColor_.r, 255 - backGroundColor_.g, 255 - backGroundColor_.b, 255));
}


SimulationState::~SimulationState()
{
}


void SimulationState::Update()
{

	if (!isPaused)
	{
		streetManager_.timeStep();
	}
	else
	{
		DisplayWindow::getRenderWindow()->setView(GUIView_);
		DisplayWindow::getRenderWindow()->draw(pausedText_);
	}

	if (shouldDraw)
	{
		DisplayWindow::getRenderWindow()->setView(simulationView_);
		streetManager_.drawStreets();
	}
}

void SimulationState::Cleanup()
{


}

void SimulationState::Display()
{

}

void SimulationState::GetEvents()
{

}

void SimulationState::Init()
{

}

void SimulationState::Pause()
{

}


void SimulationState::Resume()
{

}