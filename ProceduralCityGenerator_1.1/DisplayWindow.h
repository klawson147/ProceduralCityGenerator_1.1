#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

namespace DisplayWindow
{
	void Init();
	void Clear();
	void Render();
	void checkWindowEvents();
	bool isOpen();

	void Draw(sf::Drawable&);

	sf::Vector2u getWindowSize();
}
