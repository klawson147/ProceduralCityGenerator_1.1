#pragma once
#include <math.h>
#include <time.h>
#include "Street.h"
#include "Point.h"
#include "InitialSimValues.h"
#include "RandomNumberGenerator.h"
#define PI 3.14159265
class StreetFactory
{


public:
	StreetFactory();
	~StreetFactory();

	Street createStreetFromPoint(Point, float, float);
	Street createStreetFromPoint(float, float, float, float);
	Street createRandomStreet(sf::Vector2i, sf::Vector2i);
	Street createStreetDivision(Street, int);

	InitialSimValues pattern_;

	double getAngleBetweenTwoPoints(Point, Point);

private:
	float calculateSlope(Point, Point);
	float getPossibleXValue(Street);
	float getRandomAngle();

	float getPerpendicularAngle(float);
	float getPerpendicularAngle(float, float);
	float getUniversalAngle(float, float);


	Point getPointOnLine(Street);
	Point getPointOnLine(Street, float);

	float getUniformRandomInRange(float, float);
};

