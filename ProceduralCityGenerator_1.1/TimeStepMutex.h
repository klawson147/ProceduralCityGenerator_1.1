#pragma once
#include <SFML\Graphics.hpp>

#define MAX_FPS			60
#define SKIP_TICKS		16.666
#define MAX_FRAMESKIP	10

class TimeStepMutex
{
public:
	void Init();
	bool isLocked();

private:
	sf::Clock
		m_clock;

	unsigned long int 
		m_nextSimTick;

	unsigned int
		m_loops = 0;

};
