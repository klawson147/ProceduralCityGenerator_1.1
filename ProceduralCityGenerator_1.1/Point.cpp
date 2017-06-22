#include "Point.h"


Point::Point()
{
	Position.x = NULL;
	Position.y = NULL;
}

Point::Point(sf::Vector2f pos)
{
	Position = pos;
}


Point::~Point()
{
}
