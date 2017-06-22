#include "StreetFactory.h"

StreetFactory::StreetFactory()
{
}

StreetFactory::~StreetFactory()
{
}

// Return The Slope from 2 Points
float StreetFactory::calculateSlope(Point p1, Point p2)
{
	float m;
	float deltaY = (float)p2.Position.y - (float)p1.Position.y;
	float deltaX = (float)p2.Position.x - (float)p1.Position.x;

	m = deltaY / deltaX;

	return m;
}

// Return a Random X Value in the Range of a Street
float StreetFactory::getPossibleXValue(Street s1)
{
	if (s1.getPointA().Position.x > s1.getPointB().Position.x)
	{
		return RandomNumberGenerator::getUniformRandomInRange(s1.getPointB().Position.x, s1.getPointA().Position.x);
	}
	else
	{
		return RandomNumberGenerator::getUniformRandomInRange(s1.getPointA().Position.x, s1.getPointB().Position.x);
	}
}

// Return a Random Point on the Street s1
Point StreetFactory::getPointOnLine(Street s1)
{
	Point p1 = s1.getPointA();
	Point p2 = s1.getPointB();
	Point p3;

	float slope = calculateSlope(p1, p2);

	float newX = getPossibleXValue(s1);

	float xVec = p1.Position.x - newX;

	slope *= xVec;
	slope -= p1.Position.y;
	slope *= -1; //4th Quadrant Environment
	p3.Position.x = (newX);
	p3.Position.y = (slope);

	return p3;
}
// Return a Point on the Street s1 at position x
// no error checking
Point StreetFactory::getPointOnLine(Street s1, float newX)
{
	Point p1 = s1.getPointA();
	Point p2 = s1.getPointB();
	Point p3;

	float slope = calculateSlope(p1, p2);
	float xVec = p1.Position.x - newX;

	slope *= xVec;
	slope -= p1.Position.y;
	slope *= -1; //4th Quadant Environment
	p3.Position.x = (newX);
	p3.Position.y = (slope);

	return p3;
}

// args: initial point, distance, angle(optional)
Street StreetFactory::createStreetFromPoint(Point pLine, float distance, float angle = RandomNumberGenerator::getUniformRandomAngle())
{
	angle *= -1; // 4th Quadrant Environment

	float newx, newy; //X coord and Y coord for new end point
	Point newPoint; //End point for new line
	Street newStreet; //Street to be returned

	newx = (pLine.Position.x) + (distance * (float)cos(angle * PI / 180.0)); //Calculating new x coord
	newy = (pLine.Position.y) + (distance * (float)sin(angle * PI / 180.0)); //Calculating new y coord

	newPoint.Position.x = (newx); //Setting new end point x coord
	newPoint.Position.y = (newy); //Setting new end point y coord

	newStreet.setPointA(pLine.Position);
	newStreet.setPointB(pLine.Position);
	newStreet.setPointC(newPoint.Position); //Setting point C of street

	newStreet.setAngleDir(angle); //Setting angle of street
	//newStreet.setDistance(distance); //Setting distance of street

	return newStreet;
}
// args: initial x, initial y, distance, angle(optional)
Street StreetFactory::createStreetFromPoint(float x, float y, float distance, float angle = RandomNumberGenerator::getUniformRandomAngle())
{
	angle *= -1; // 4th Quadrant Environment

	float newx, newy; //X coord and Y coord for new end point
	Point newPoint; //End point for new line
	Street newStreet; //Street to be returned

	newx = (x)+(distance * cos(angle * PI / 180.0)); //Calculating new x coord
	newy = (y)+(distance * sin(angle * PI / 180.0)); //Calculating new y coord

	newPoint.Position.x = (newx); //Setting new end point x coord
	newPoint.Position.y = (newy); //Setting new end point y coord

	newStreet.setPointA(sf::Vector2f(x, y));
	newStreet.setPointB(sf::Vector2f(x, y));
	newStreet.setPointC(newPoint.Position); //Setting point C of street

	newStreet.setAngleDir(angle); //Setting angle of street
	//newStreet.setDistance(distance); //Setting distance of street
	//getAngleBetweenTwoPoints(newStreet.getPointA(), newStreet.getPointC());

	return newStreet;
}

Street StreetFactory::createRandomStreet(sf::Vector2i lb, sf::Vector2i up)
{
	Street newStreet;

	float x1 = rand() % (up.x - lb.x) + (lb.x);
	float y1 = rand() % (up.y - lb.y) + (lb.y);

	float x2 = rand() % (up.x - lb.x) + (lb.x);
	float y2 = rand() % (up.y - lb.y) + (lb.y);

	newStreet.setPointA(sf::Vector2f(x1, y1));
	newStreet.setPointB(sf::Vector2f(x2, y2));
	newStreet.setPointC(sf::Vector2f(x2, y2));

	return newStreet;
}

// Get a random perpendicular angle
float StreetFactory::getPerpendicularAngle(float angle)
{
	int result = RandomNumberGenerator::getUniformRandomInRange(0, 1);
	angle *= -1;
	if (result == 1)
	{
		angle += 90;

		if (angle > 359)
		{
			angle -= 360;
			return angle;
		}
	}
	else
	{
		angle -= 90;

		if (angle < 0)
		{
			angle = 360 + angle;
			return angle;
		}
	}
	return angle;
}


float StreetFactory::getUniversalAngle(float origin, float angle)
{
	int result = RandomNumberGenerator::getUniformRandomInRange(0, 1);
	origin *= -1;
	if (result == 1)
	{
		origin += angle;

		if (origin > 359)
		{
			origin -= 360;
			return origin;
		}
	}
	else
	{
		origin -= angle;

		if (origin < 0)
		{
			origin = 360 + origin;
			return origin;
		}
	}
	return origin;
}

// Get a perpendicular angle
//  1  positive
// -1  negative
float StreetFactory::getPerpendicularAngle(float angle, float direction)
{
	int perp = (90 * direction);

	angle += perp;

	if (angle > 359)
	{
		angle -= 359;
		return angle;
	}

	if (angle < 0)
	{
		angle = 360 + angle;
		return angle;
	}
	return angle;
}

// Create Division
Street StreetFactory::createStreetDivision(Street original, int streeInstance)
{
	Street temp = createStreetFromPoint(original.getPointB(),
		RandomNumberGenerator::getUniformRandomInRange(pattern_.streetDistanceMin, pattern_.streetDistanceMax),
		getUniversalAngle(original.getAngle(), RandomNumberGenerator::getUniformRandomInRange(pattern_.streetDivisionAngleMin, pattern_.streetDivisionAngleMax)));

	temp.m_streetID = streeInstance;
	temp.setColor(sf::Color::Red);
	temp.m_parentID = original.m_streetID;
	return temp;
}

// Get Angle From Point A to B based on Origin
double StreetFactory::getAngleBetweenTwoPoints(Point A, Point B)
{
	double x = A.Position.x - B.Position.x;
	double y = A.Position.y - B.Position.y;

	x = std::pow((double)x, 2);
	y = std::pow((double)y, 2);

	double d = std::abs(sqrt((double)x + (double)y));

	double angle = std::atan2f((double)y, (double)x);
	angle = (angle * 180) / std::_Pi;

	return angle;
}