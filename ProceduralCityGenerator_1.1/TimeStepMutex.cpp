#include "TimeStepMutex.h"

void TimeStepMutex::Init()
{
	m_nextGameTick = m_permClock.getElapsedTime().asMicroseconds();
}

bool TimeStepMutex::isLocked()
{
	// If true, locked.
	if (m_clock.getElapsedTime().asMicroseconds() > m_nextGameTick
		&& m_loop < m_maxFrameSkip)
	{
		m_nextGameTick += (sf::Int64)m_skipTicks;
		m_loop++;

		return true;
	}
	// if false, unlocked.
	else
	{
		m_loop = 0;
		return false;
	}
}