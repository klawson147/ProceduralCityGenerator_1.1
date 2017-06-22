#include "ExitButton.h"

ExitButton::ExitButton(sf::Vector2f	position, const std::string	text, const std::string	textUpper) : IButton(position, text, textUpper)
{
}

ExitButton::~ExitButton()
{
}

void ExitButton::Click()
{
	DisplayWindow::Close();
}