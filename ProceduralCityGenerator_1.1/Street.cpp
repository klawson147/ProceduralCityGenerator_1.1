#include "Street.h"

int Street::instances = 0;

Street::Street()
{
	m_maxDistDivisions = 25;
	m_color = sf::Color::White;
	m_p_parent = nullptr;
	m_shouldDivide = true;
	m_shouldDivideEnd = true;
	m_isMaster = false;
}


Street::~Street()
{
}

Point Street::getPointFromDistance(
	Point initialPoint,
	float distance,
	int angle)
{
	Point newPoint;
	newPoint.Position.x = ((initialPoint.Position.x) + (distance * (float)cos(angle * PI / 180.0))); //Calculating new x coordinate
	newPoint.Position.y = ((initialPoint.Position.y) + (distance * (float)sin(angle * PI / 180.0))); //Calculating new y coordinate

	return newPoint;
}

void Street::setPointA(sf::Vector2f pos)
{
	m_pointA.Position = pos;
}

void Street::setPointB(sf::Vector2f pos)
{
	m_pointB.Position = pos;
}

void Street::setPointC(sf::Vector2f pos)
{
	m_pointC.Position = pos;
}

sf::Vertex Street::getVertexA()
{
	sf::Vertex v;
	v.color = m_color;
	v.position.x = m_pointA.Position.x;
	v.position.y = m_pointA.Position.y;
	return v;
}

sf::Vertex Street::getVertexB()
{
	sf::Vertex v;
	v.color = m_color;
	v.position.x = m_pointB.Position.x;
	v.position.y = m_pointB.Position.y;
	return v;
}

sf::Vertex Street::getVertexC()
{
	sf::Vertex v;
	v.color = m_color;
	v.position.x = m_pointC.Position.x;
	v.position.y = m_pointC.Position.y;
	return v;
}

Point Street::getPointA()
{
	return m_pointA;
}

Point Street::getPointB()
{
	return m_pointB;
}

Point Street::getPointC()
{
	return m_pointC;
}

void Street::setAngleDir(int dir)
{
	m_angleDir = dir;
}

void Street::setAngleDir(float dir)
{
	m_angleDir = dir;
}

// Returns true if street still growing
// Returns false if street done growing
bool Street::grow()
{
	int distance = calculatePointDistance(m_pointB, m_pointC);

	if (distance <= 4)
	{
		m_pointB = m_pointC;
		return false;
	}
	else if (distance != 0)
	{
		m_pointB = getPointFromDistance(m_pointB, 1, m_angleDir);
		return true;
	}

	return false;
}

int Street::calculatePointDistance(Point p1, Point p2)
{

	float xDis = (p2.Position.x - p1.Position.x);
	float yDis = (p2.Position.y - p1.Position.y);


	return std::sqrt(xDis * xDis + yDis * yDis);

}

float Street::calculateDistanceAC()
{
	return calculatePointDistance(m_pointA, m_pointC);
}

float Street::calculateDistanceBC()
{
	return calculatePointDistance(m_pointB, m_pointC);
}

int Street::getAngle()
{
	return m_angleDir;
}

// Returns True if Street contains Child ID
bool Street::containsChild(int id)
{
	
	for (size_t i = 0; i < childID.size(); i++)
	{
		if (childID[i] == id)
			return true;
	}
	return false;
}

void Street::setColor(sf::Color c)
{
	m_color = c;
}

