#include "TimeStepMutex.h"

void TimeStepMutex::Init()
{
	m_nextSimTick = m_clock.getElapsedTime().asMilliseconds();
}

bool TimeStepMutex::isLocked()
{
	// If true, locked.
	if (m_clock.getElapsedTime().asMilliseconds() > (sf::Int32)m_nextSimTick
		&& m_loops < MAX_FRAMESKIP)
	{
		m_nextSimTick += (unsigned long int)SKIP_TICKS;
		m_loops += 1;
		return true;
	}
	// if false, unlocked.
	else
	{
		m_loops = 0;

		return false;
	}
}