#pragma once
#include "IState.h"
#include "StreetManager.h"
#include "DisplayWindow.h"
#include "InitialSimValues.h"

class SimulationState :
	public IState
{
public:
	SimulationState(StateManager* stateManager);
	~SimulationState();

	void				reset_();
	void				setPattern(InitialSimValues);
	bool				isPatternSet();
	// Executed at the beginning of each state
	void Init();

	// Occurs when the state is left
	void Cleanup();

	// Execute code to pause a state
	void Pause();

	// Execute code to resume a state
	void Resume();

	// Recieves and process input
	void GetEvents();

	// Occurs each frame/timestep
	void Update();

	// Draw this state
	void Display();

private:
	StreetManager		streetManager_;

	sf::View			simulationView_;
	sf::View			GUIView_;

	sf::Font			pausedFont_;
	sf::Text			pausedText_;
	sf::Text			streetCountText_;

	int					loops;
	bool				isPaused = false;
	bool				isSpaceDown = false;

	bool				shouldDraw = true;
	bool				isQDOwn = false;

	sf::Color			backGroundColor_;

	InitialSimValues pattern_;

};

