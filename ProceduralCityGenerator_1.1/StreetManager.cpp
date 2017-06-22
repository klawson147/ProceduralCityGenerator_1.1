#include "StreetManager.h"

// Default Constructor
StreetManager::StreetManager()
{
	executionCount = 0;

	intersectionPointX = new float;
	intersectionPointY = new float;
}
// Set Window Reference
void StreetManager::setWindowReference(sf::RenderWindow* renderWindow)
{
	rw_ = renderWindow;
}

StreetManager::~StreetManager()
{
}

// Draw All Streets
void StreetManager::drawStreets()
{
	sf::VertexArray va;
	va.setPrimitiveType(sf::Lines);

	for (auto i = finishedStreets_.begin(); i != finishedStreets_.end(); i++)
	{
		va.append(i->getVertexA());
		va.append(i->getVertexB());

		DisplayWindow::Draw(va);
		va.clear();
	}

	for (auto i = growingStreets_.begin(); i != growingStreets_.end(); i++)
	{
		va.append(i->getVertexA());
		va.append(i->getVertexB());

		DisplayWindow::Draw(va);
		va.clear();
	}
}

// Set Starting Position
void StreetManager::setStartingPoint(sf::Vector2f position, InitialSimValues pattern)
{
	startingPoint_.Position.x = (position.x);
	startingPoint_.Position.y = (position.y);

	algorithmValues_ = pattern;
	streetFactory.pattern_ = pattern;
}

// Returns 1 if the lines intersect, otherwise 0. If the lines
// intersect the intersection point may be stored in the floats intersectionPointX and intersectionPointY
bool StreetManager::getLineIntersection(Point p1, Point p2, Point p3, Point p4)
{
	float s1_x, s1_y, s2_x, s2_y;
	s1_x = p2.Position.x - p1.Position.x;
	s1_y = p2.Position.y - p1.Position.y;

	s2_x = p4.Position.x - p3.Position.x;
	s2_y = p4.Position.y - p3.Position.y;

	float denominator = -s2_x * s1_y + s1_x * s2_y;

	if (denominator == 0)
	{
		return false;
	}

	float s, t;
	s = (-s1_y * (p1.Position.x - p3.Position.x) + s1_x * (p1.Position.y - p3.Position.y)) / denominator;
	t = (s2_x * (p1.Position.y - p3.Position.y) - s2_y * (p1.Position.x - p3.Position.x)) / denominator;

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		// Collision detected
		*intersectionPointX = p1.Position.x + (t * s1_x);
		*intersectionPointY = p1.Position.y + (t * s1_y);
		return true;
	}
	return false; // No collision
}

// Set Initial Street(s) Values
void StreetManager::setInitialStreet()
{
	growingStreets_.clear();
	finishedStreets_.clear();

	growingStreets_.reserve(3000);
	finishedStreets_.reserve(algorithmValues_.maxNumbStreets + 1000);

	Street::instances = 0;

	Street temp;

	for (int i = 0; i < algorithmValues_.startingNumbStreets; i++)
	{
		temp = streetFactory.createStreetFromPoint(
			rw_->getSize().x / 2,
			rw_->getSize().y / 2,
			RandomNumberGenerator::getUniformRandomInRange(algorithmValues_.startingStreetDistanceMin, algorithmValues_.startingStreetDistanceMax),
			i*(360 / algorithmValues_.startingNumbStreets));

		temp.m_isMaster = true;
		temp.m_parentID = -1;
		temp.m_streetID = Street::instances++;
		temp.setColor(GROWING_COLOR);

		if (streetWillIntersect(temp))
		{
			temp.m_shouldDivideEnd = false;
			temp.setPointC(sf::Vector2f(*intersectionPointX, *intersectionPointY));
		}

		growingStreets_.push_back(temp);
	}
}

// Time Step
void StreetManager::timeStep()
{
	growStreets();
	divideStreets();
}


void StreetManager::divideStreets()
{
	std::vector<Street>::iterator it;
	int randomvalue;

	if (growingStreets_.size() + finishedStreets_.size() < algorithmValues_.maxNumbStreets)
	{
		for (it = growingStreets_.begin(); it != growingStreets_.end(); it++)
		{
			it->m_maxDistDivisions -= 1;
			randomvalue = RandomNumberGenerator::getUniformRandomInRange(1, algorithmValues_.divisionPercentChance);

			if (randomvalue == 1 && it->m_maxDistDivisions < 0 && it->m_shouldDivide == true)
			{
				it->m_maxDistDivisions = algorithmValues_.minimumDistanceBetweenDivisions;
				Street temp = streetFactory.createStreetDivision(*it, Street::instances);
				it->childID.push_back(Street::instances);
				Street::instances++;

				if (streetWillIntersect(temp))
				{
					temp.m_shouldDivideEnd = false;
					temp.setPointC(sf::Vector2f(*intersectionPointX, *intersectionPointY));
				}
				growingStreets_.push_back(temp);

			}
		}
	}
}

// Simulate Realtime Effect by "Growing" Street
void StreetManager::growStreets()
{
	for (std::size_t i = 0; i < growingStreets_.size(); i++)
	{
		if (growingStreets_.at(i).grow() == false)
		{
			if (growingStreets_[i].m_shouldDivideEnd == true)
			{
				if (growingStreets_.size() + finishedStreets_.size() < algorithmValues_.maxNumbStreets)
				{
					// Create New Street at end of Finished Street
					Street temp = streetFactory.createStreetDivision(growingStreets_[i], Street::instances);
					growingStreets_[i].childID.push_back(temp.m_streetID);

					if (streetWillIntersect(temp))
					{
						temp.m_shouldDivideEnd = false;
						temp.setPointC(sf::Vector2f(*intersectionPointX, *intersectionPointY));
					}
					growingStreets_.push_back(temp);

				}
			}

			// Move Street to Finished Vector
			growingStreets_.at(i).setColor(FINISHED_COLOR);
			finishedStreets_.push_back(growingStreets_.at(i));
			growingStreets_.erase(growingStreets_.begin() + i);
			Street::instances++;
		}
	}
}

// Return True if A intersects B
// Filters out Parents
// Filters out Same Street
// Filters out Children
// Filters out Master Streets
bool StreetManager::streetIntersects(Street A, Street B)
{
	if (A.m_parentID == B.m_streetID || A.m_streetID == B.m_parentID || A.m_streetID == B.m_streetID || (A.m_isMaster && B.m_isMaster))
		return false;

	if (!A.containsChild(B.m_streetID))
	{
		if (getLineIntersection(A.getPointA(), A.getPointC(), B.getPointA(), B.getPointC()))
		{
			return true;
		}
	}

	return false;
}

// Return True if Street Will Intersect
// Intersection Point is Stored in
// intersectionPointX, intersectionPointY
bool StreetManager::streetWillIntersect(Street s)
{
	std::vector<sf::Vector2f> intersectionPoints;

	for (std::vector<Street>::iterator it = growingStreets_.begin(); it != growingStreets_.end(); it++)
	{
		if (streetIntersects(s, *it))
		{
			intersectionPoints.push_back(sf::Vector2f(*intersectionPointX, *intersectionPointY));
		}
	}

	for (std::vector<Street>::iterator it = finishedStreets_.begin(); it != finishedStreets_.end(); it++)
	{
		if (streetIntersects(s, *it))
		{
			intersectionPoints.push_back(sf::Vector2f(*intersectionPointX, *intersectionPointY));
		}
	}

	if (!intersectionPoints.empty())
	{
		int d = INT_MAX;

		float x2, x1, y2, y1;
		x1 = s.getPointA().Position.x;
		y1 = s.getPointA().Position.y;

		for (std::vector<sf::Vector2f>::iterator it = intersectionPoints.begin(); it != intersectionPoints.end(); it++)
		{
			x2 = it->x;
			y2 = it->y;

			if (std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)) < d)
			{
				d = std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
				*intersectionPointX = x2;
				*intersectionPointY = y2;
			}
		}

		return true;
	}

	return false;
}

// Set Algorithm Values
void StreetManager::setAlgorithmValues(InitialSimValues values)
{
	algorithmValues_ = values;
	streetFactory.pattern_ = values;
}

// Unusued Functionality
bool StreetManager::snapToPoint(Street street)
{
	std::vector<sf::Vector2f> intersectionPoints;
	std::vector<Street>::iterator it = growingStreets_.begin();

	for (it; it != growingStreets_.end(); it++)
	{
		if (it->m_streetID != street.m_streetID && it->m_parentID != street.m_streetID && street.m_parentID != it->m_streetID)
		{
			if (street.calculatePointDistance(it->getPointC(), street.getPointC()) < 5)
			{
				intersectionPoints.push_back(sf::Vector2f(it->getPointC().Position));
			}
			if (street.calculatePointDistance(it->getPointA(), street.getPointC()) < 5)
			{
				intersectionPoints.push_back(sf::Vector2f(it->getPointA().Position));
			}
		}
	}

	it = finishedStreets_.begin();

	for (it; it != finishedStreets_.end(); it++)
	{
		if (it->m_streetID != street.m_streetID && it->m_parentID != street.m_streetID && street.m_parentID != it->m_streetID)
		{
			if (street.calculatePointDistance(it->getPointC(), street.getPointC()) < 5)
			{
				intersectionPoints.push_back(sf::Vector2f(it->getPointC().Position));
			}
			if (street.calculatePointDistance(it->getPointA(), street.getPointC()) < 5)
			{
				intersectionPoints.push_back(sf::Vector2f(it->getPointA().Position));
			}
		}
	}

	if (intersectionPoints.empty())
	{
		return false;
	}
	else
	{
		int d = INT_MAX;

		float x2, x1, y2, y1;
		x1 = street.getPointA().Position.x;
		y1 = street.getPointA().Position.y;

		for (std::vector<sf::Vector2f>::iterator it = intersectionPoints.begin(); it != intersectionPoints.end(); it++)
		{
			x2 = it->x;
			y2 = it->y;

			if (std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)) < d)
			{
				d = std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
				*intersectionPointX = x2;
				*intersectionPointY = y2;
			}
		}
		return true;
	}
}