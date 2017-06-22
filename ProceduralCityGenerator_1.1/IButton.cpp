#include "IButton.h"

IButton::IButton(sf::Vector2f position, const std::string name, const std::string nameUpper = "")
{
	m_shape.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_shape.setFillColor(sf::Color::Black);
	m_shape.setOutlineThickness(3);
	m_shape.setOutlineColor(sf::Color(199, 199, 199));
	m_shape.setPosition(position);

	m_text.setFont(ResourceHolder::get().getFont(FontName::sf_atarian_system));
	m_text.setCharacterSize(28);
	m_text.setColor(sf::Color(255, 255, 255, 255));
	m_text.setString(name);
	m_text.setPosition(
		(position.x + (BUTTON_WIDTH / 2) - ((m_text.getCharacterSize() / 6) * m_text.getString().getSize())), 
		(m_shape.getPosition().y));

	m_textUpper.setFont(ResourceHolder::get().getFont(FontName::sf_atarian_system));
	m_textUpper.setCharacterSize(28);
	m_textUpper.setColor(sf::Color(255, 255, 255, 255));
	m_textUpper.setString(name);
	m_textUpper.setPosition(
		(position.x + (BUTTON_WIDTH / 2) - ((m_text.getCharacterSize() / 6) * m_text.getString().getSize())),
		(m_shape.getPosition().y));
}

IButton::~IButton()
{
}

bool IButton::Contains(const sf::Vector2f& mousePosition)
{
	sf::FloatRect floatRect(m_shape.getPosition(), m_shape.getSize());

	if (floatRect.contains(mousePosition))
	{
		Update();
		return true;
	}

	return false;
}


void IButton::Display()
{
	DisplayWindow::Draw(m_shape);
	DisplayWindow::Draw(m_text);
	DisplayWindow::Draw(m_textUpper);
}