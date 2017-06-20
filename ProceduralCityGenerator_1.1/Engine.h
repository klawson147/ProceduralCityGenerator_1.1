#include "StateManager.h"
#include "DisplayWindow.h"
#include "TimeStepMutex.h"

#include "SplashScreenState.h"
#include "MainMenuState.h"

#pragma once
class Engine
{
public:
	// Returns True if Initialization Successfull
	bool Initialize();

	// Returns True if Successfull run
	bool Start();

	Engine();
	~Engine();

private:
	StateManager m_stateManager;

	TimeStepMutex m_timeStepMutex;
};
