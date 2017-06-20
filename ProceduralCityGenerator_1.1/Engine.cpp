#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::Initialize()
{
	m_p_displayWindow = new DisplayWindow();
	m_p_displayWindow->Init();

	m_timeStepMutex.Init();

	m_stateManager.PushState(new MainMenuState(&m_stateManager));
	m_stateManager.PushState(new SplashScreenState(&m_stateManager));

	return true;
}

bool Engine::Start()
{
	while (m_p_displayWindow->isOpen())
	{
		// Check for window events
		m_p_displayWindow->checkWindowEvents();

		// Clear window
		m_p_displayWindow->Clear();

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
		m_p_displayWindow->Render();
	}

	return true;
}