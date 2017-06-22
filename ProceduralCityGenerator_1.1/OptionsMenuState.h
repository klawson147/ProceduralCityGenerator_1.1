#pragma once
#include "IState.h"
class OptionsMenuState :
	public IState
{
public:
	OptionsMenuState(StateManager*);
	~OptionsMenuState();
};

