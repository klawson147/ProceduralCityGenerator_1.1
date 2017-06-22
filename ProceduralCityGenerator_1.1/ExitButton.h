#pragma once
#include "IButton.h"
class ExitButton :
	public IButton
{
public:
	ExitButton(sf::Vector2f				position,
		const std::string			text,
		const std::string			textUpper);
	~ExitButton();

	void Click();

private:

};
