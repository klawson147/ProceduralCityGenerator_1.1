#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "StateManager.h"
#include "DisplayWindow.h"

#define BUTTON_WIDTH 145
#define BUTTON_HEIGHT 40

class IButton
{
public:
	IButton(sf::Vector2f position, const std::string text, const std::string textUpper);
	~IButton();

	bool
		Contains(const sf::Vector2i& mousePosition);

	void
		Display();

	virtual void
		Click() = 0;

protected:
	sf::RectangleShape	m_shape;
	sf::Text			m_text;
	sf::Text			m_textUpper;

	
};
