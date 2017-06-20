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

	_stateManager.PushState(new MainMenuState(&_stateManager));
	_stateManager.PushState(new SplashScreenState(&_stateManager));

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

		// Check for specific state events
		_stateManager.GetCurrentState()->GetEvents();

		// Update current state
		_stateManager.GetCurrentState()->Update();

		// Draw current state to window
		_stateManager.GetCurrentState()->Display();
		
		// Draw current screen to user
		m_p_displayWindow->Render();

	}

	return true;
}
