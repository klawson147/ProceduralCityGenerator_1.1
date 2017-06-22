#pragma once
#include "Point.h"

#define PI 3.14159265

class Street
{
public:
	Street();
	~Street();

	static int instances;

	int
		m_streetID,
		m_parentID,
		m_maxDistDivisions;

	Street*
		m_p_parent;

	bool
		m_isMaster,
		m_shouldDivide,
		m_shouldDivideEnd;

	std::vector<int>
		childID;

public:
	void setColor(sf::Color);
	void setPointA(sf::Vector2f);
	void setPointB(sf::Vector2f);
	void setPointC(sf::Vector2f);
	void setDistance(float);
	void setAngleDir(int);
	void setAngleDir(float);
	void setMaxDivisions(int);
	void incrementDivisions();

	int
		getAngle(),
		getNumbDiv();

	int
		calculatePointDistance(Point, Point);

	sf::Vertex
		getVertexA(),
		getVertexB(),
		getVertexC();

	Point
		getPointA(),
		getPointB(),
		getPointC(),

		getPointFromDistance(
		Point initial,
		float distance,
		int angle
		);

	bool
		grow(),
		containsChild(int);

	float
		calculateDistanceAC(),
		calculateDistanceBC();

private:
	Point
		m_pointA,
		m_pointB,
		m_pointC;

	float
		m_angleDir;

	sf::Color
		m_color;
};
