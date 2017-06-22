#include "TextFieldButton.h"

TextFieldButton::TextFieldButton(UserFields userField, sf::Vector2f position,
	const std::string text,
	const std::string textUpper,
	int lower,
	int upper) : IButton(position, text, textUpper)
{
	m_field = userField;
	m_minVal = lower;
	m_maxVal = upper;
}

TextFieldButton::~TextFieldButton()
{
}

void TextFieldButton::Click()
{
	if (m_isHighlighted)
	{
		m_isSelected = true;
		m_shape.setOutlineColor(sf::Color::Red);
	}
	else
	{
		m_isSelected = false;
		m_shape.setOutlineColor(sf::Color(199, 199, 199, 255));
	}

	return;
}

bool TextFieldButton::isSelection()
{
	return m_isSelected;
}

bool TextFieldButton::Contains(const sf::Vector2i& mousePosition)
{
	sf::FloatRect floatRect(m_shape.getPosition(), m_shape.getSize());

	if (floatRect.contains(mousePosition.x, mousePosition.y))
	{
		m_isHighlighted = true;
		return true;
	}
	else
	{
		m_isHighlighted = false;
		return false;
	}
}

void TextFieldButton::insertValue(char addition)
{
	std::string add(1, addition);

	if (!isValidInput(add))
	{
		return;
	}

	if (m_text.getString().getSize() <= m_maxDigits)
	{
		std::string str = m_text.getString() + addition;
		m_text.setString(str);
	}

	int val = getIntValue();
	if (val < m_minVal)
	{
		m_text.setString(std::to_string(m_minVal));
	}
	else if (val > m_maxVal)
	{
		m_text.setString(std::to_string(m_maxVal));
	}
	else
	{
	}
}

void TextFieldButton::backspace()
{
	std::string str = m_text.getString();
	if (str.length() != 0)
	{
		str.pop_back();

	}
	
	m_text.setString(str);
}

void TextFieldButton::clearText()
{
	m_text.setString("");
}

std::string TextFieldButton::getStringValue()
{
	return m_text.getString();
}

int TextFieldButton::getIntValue()
{
	std::string::size_type sz;
	std::string str = m_text.getString();
	return std::stoi(str, &sz);
}

bool TextFieldButton::isValidInput(std::string input)
{
	std::string::size_type sz;
	bool isValid = true;

	try {
		std::stoi(input, &sz);
	}
	catch (const std::invalid_argument& ia)
	{
		isValid = false;
	}

	return isValid;
}

void TextFieldButton::setLimits(unsigned int lower, unsigned int upper)
{
	m_minVal = lower;
	m_minVal = upper;
}

void TextFieldButton::setDescription(std::string desc)
{
	m_textUpper.setString(desc);
}