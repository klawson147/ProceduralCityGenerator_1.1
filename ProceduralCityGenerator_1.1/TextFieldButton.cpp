#include "TextFieldButton.h"


TextFieldButton::TextFieldButton(UserFields userField, sf::Vector2f position,
	const std::string text,
	const std::string textUpper) : IButton(position, text, textUpper)
{
	m_field = userField;
}


TextFieldButton::~TextFieldButton()
{

}


void TextFieldButton::Click()
{
	return;

}

bool TextFieldButton::isSelection()
{
	return isSelected;
}

bool TextFieldButton::Contains(const sf::Vector2i& mousePosition)
{
	sf::FloatRect floatRect(m_shape.getPosition(), m_shape.getSize());


	if (floatRect.contains(mousePosition.x, mousePosition.y))
	{
		isSelected = true;
		return true;
	}
	{
		isSelected = false;
		return false;
	}
}

void TextFieldButton::insertValue(std::string addition)
{
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
	str.pop_back();
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