#pragma once
#include <SFML\Graphics.hpp>


class TimeStepMutex
{
public:
	void Init();
	bool isLocked();

private:
	sf::Clock
		m_clock;

	sf::Time
		m_timeSinceLastUpdate = sf::Time::Zero;

	const sf::Time
		m_c_timePerFrame = sf::seconds(1.f / 60.f);

};
