#pragma once
#include <SFML\Graphics.hpp>

struct StreetManagerInitializationValues
{
	// --- Initial Street Configuration --- //
	int				startingNumbStreets = 15;
	int				startingStreetDistanceMin = 1000;
	int				startingStreetDistanceMax = 1000;

	// --- General Rules & Parameters --- //
	int				maxNumbStreets = 25000;
	int				streetDistanceMin = 100;
	int				streetDistanceMax = 300;
	int				divisionPercentChance = 25;

	int				streetDivisionAngleMin = 90;
	int				streetDivisionAngleMax = 90;
	int				minimumDistanceBetweenDivisions = 25;

	bool			nullFlag = true;
};
