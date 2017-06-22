#pragma once
#include "IState.h"
class SettingsMenuState :
	public IState
{
public:
	SettingsMenuState(StateManager*);
	~SettingsMenuState();
};

