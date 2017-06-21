#pragma once
#include <SFML\Graphics.hpp>

class TimeStepMutex
{
public:
	void Init();
	bool isLocked();

private:
	sf::Clock
		m_clock,
		m_permClock;

	int
		m_loop = 0;

	sf::Int64
		m_nextGameTick;

	const int
		m_maxFPS = 60,
		m_maxFrameSkip = 10;

	const float
		m_skipTicks = (1000 / (const float)m_maxFPS);
};
