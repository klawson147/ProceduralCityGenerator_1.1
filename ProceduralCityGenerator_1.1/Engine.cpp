#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::Initialize()
{
	DisplayWindow::Init();

	m_timeStepMutex.Init();

	m_stateManager.PushState(new MainMenuState(&m_stateManager));
	m_stateManager.PushState(new SplashScreenState(&m_stateManager));

	return true;
}

bool Engine::Start()
{
	while (DisplayWindow::isOpen())
	{
		// Check for window events
		DisplayWindow::checkWindowEvents();

		// Clear window
		DisplayWindow::Clear();

		// Locked Time Step
		while (m_timeStepMutex.isLocked())
		{
			// Check for specific state events
			m_stateManager.GetCurrentState()->GetEvents();

			// Update current state
			m_stateManager.GetCurrentState()->Update();

			// Draw current state to window
			m_stateManager.GetCurrentState()->Display();
		}

		// Draw current screen to user
		DisplayWindow::Render();
	}

	return true;
}