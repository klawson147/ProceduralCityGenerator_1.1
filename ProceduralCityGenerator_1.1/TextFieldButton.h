#pragma once
#include "IButton.h"
#include "UserFields.h"

class TextFieldButton :
	public IButton
{
public:
	TextFieldButton(
		UserFields field,
		sf::Vector2f position, 
		const std::string text, 
		const std::string textUpper);
	~TextFieldButton();

	std::string getStringValue();
	int			getIntValue();

	void		insertValue(std::string);
	void		backspace();
	void		clearText();
	bool		Contains(const sf::Vector2i& mousePosition);
	void		Click();

	bool		isSelection();

	void		setLimits(unsigned int, unsigned int);

	void		setDescription(std::string);

protected:
	bool		isValidInput(std::string);

private:
	UserFields	m_field;

	bool		isSelected;
	
	int			m_minVal = 0;
	int			m_maxVal = 0;
	const int m_maxDigits = 5;

};

