#include "TimeStepMutex.h"

void TimeStepMutex::Init()
{
	
}

bool TimeStepMutex::isLocked()
{
	sf::Time elapsedTime = m_clock.restart();

	m_timeSinceLastUpdate += elapsedTime;

	// If true, locked.
	if (m_timeSinceLastUpdate > m_c_timePerFrame)
	{
		m_timeSinceLastUpdate -= m_c_timePerFrame;

		return true;
	}
	// if false, unlocked.
	else
	{
		return false;
	}
}