#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

#define WINDOW_MARGIN 20

enum class DisplayWindowPosition {
	top_left,
	top_center,
	top_right,

	center_left,
	center_center,
	center_right,

	bottom_left,
	bottom_center,
	bottom_right
};

namespace DisplayWindow
{
	void Init();
	void Clear();
	void Render();
	void Close();
	bool isOpen();

	sf::RenderWindow* getRenderWindow();

	void
		setSize(sf::Vector2u);

	void setAntiAlias(int);

	sf::Vector2u
		getSize();

	int
		getAntiAlias();

	void Draw(sf::Drawable&);

	sf::Vector2f getRelativePosition(
		DisplayWindowPosition,
		sf::Vector2f,
		sf::Vector2f);
}
