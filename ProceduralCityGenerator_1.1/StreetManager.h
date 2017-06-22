#include "StreetFactory.h"
#include "Point.h"
#include <vector>
#include "RandomNumberGenerator.h"
#include "DisplayWindow.h"
#include "InitialSimValues.h"
#include <algorithm>
#pragma once

#define GROWING_COLOR sf::Color::Red
#define FINISHED_COLOR sf::Color::Black

class StreetManager
{
public:

	StreetManager();
	~StreetManager();

	void	drawStreets();
	void	setStartingPoint(sf::Vector2f, InitialSimValues);
	void	timeStep();

	void	setInitialStreet();
	int		executionCount;
	void	setWindowReference(sf::RenderWindow*);
	void	setAlgorithmValues(InitialSimValues);

private:
	float*			intersectionPointX;
	float*			intersectionPointY;
	bool			getLineIntersection(Point p1, Point p2, Point p3, Point p4);
	bool			streetWillIntersect(Street);

	Point			startingPoint_;
	StreetFactory	streetFactory;
	sf::RenderWindow* rw_;
	std::vector<Street> finishedStreets_;
	std::vector<Street> growingStreets_;

	void			divideStreets();
	void			checkLifeTime(Street);
	void			growStreets();
	void			checkGlobalBounds();
	void			checkLocalBounds();
	bool			streetIntersects(Street, Street);
	Street			createBranch(Street&);

	bool			snapToPoint(Street);

	InitialSimValues algorithmValues_;
};
