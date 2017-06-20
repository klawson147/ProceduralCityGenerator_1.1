#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class DisplayWindow
{
public:

	void Init();
	void Clear();
	void Render();
	void checkWindowEvents();
	bool isOpen();

	DisplayWindow();
	~DisplayWindow();

private:
	sf::RenderWindow* m_p_renderWindow;

	void closeWindow();
	void resizeWindow(sf::Vector2f);
};

