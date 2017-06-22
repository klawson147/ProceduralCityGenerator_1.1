#include "CycleButton.h"

CycleButton::CycleButton(StateManager* sm,
	CycleOptions option,
	sf::Vector2f	position,
	const std::string	text,
	const std::string	textUpper) : IButton(position, text, textUpper)
{

	m_text.setPosition(
		(m_shape.getPosition().x + 55),
		(m_shape.getPosition().y));

	m_p_stateManager = sm;
	m_option = option;

	switch (option)
	{
	case 0:
		switch (DisplayWindow::getSize().x)
		{
		case 1366:
			m_text.setString("1366×768");
			m_selection = 1;
			break;
		case 1600:
			m_text.setString("1600x900");
			m_selection = 2;
			break;
		case 1920:
			m_text.setString("1920x1080");
			m_selection = 3;
			break;
		case 1280:
			m_text.setString("1280x720");
			m_selection = 0;
			break;
		default:
			m_text.setString("1280x720");
			m_selection = 0;
			break;
		}
		break;
	case 1:
		switch (DisplayWindow::getAntiAlias())
		{
		case 0:
			m_text.setString("0X");
			m_selection = 0;
			break;
		case 1:
			m_text.setString("2X");
			m_selection = 1;
			break;
		case 2:
			m_text.setString("4X");
			m_selection = 2;
			break;
		case 3:
			m_text.setString("8X");
			m_selection = 3;
			break;
		default:
			m_text.setString("0X");
			m_selection = 0;
			break;
		}
		break;
	}
}

CycleButton::~CycleButton()
{
}

void CycleButton::Click()
{
	switch (m_option)
	{
	case CycleOptions::Resolution:
		switch (m_selection)
		{
		case 0:
			m_text.setString("1366×768");
			DisplayWindow::setSize(sf::Vector2u(1366, 768));
			m_selection++;
			break;
		case 1:
			m_text.setString("1600x900");
			DisplayWindow::setSize(sf::Vector2u(1600, 900));
			m_selection++;
			break;
		case 2:
			m_text.setString("1920x1080");
			DisplayWindow::setSize(sf::Vector2u(1920, 1080));
			m_selection++;
			break;
		case 3:
			m_text.setString("1280x720");
			DisplayWindow::setSize(sf::Vector2u(1280, 720));
			m_selection = 0;
			break;
		default:
			m_text.setString("1280x720");
			DisplayWindow::setSize(sf::Vector2u(1280, 720));
			m_selection = 0;
			break;
		}
	break;
	case CycleOptions::AntiAlias:
		switch (m_selection)
		{
		case 0:
			m_text.setString("2X");
			DisplayWindow::setAntiAlias(2);
			m_selection++;
			break;
		case 1:
			m_text.setString("4X");
			DisplayWindow::setAntiAlias(4);
			m_selection++;
			break;
		case 2:
			m_text.setString("8X");
			DisplayWindow::setAntiAlias(8);
			m_selection++;
			break;
		case 3:
			m_text.setString("0X");
			DisplayWindow::setAntiAlias(0);
			m_selection = 0;
			break;
		default:
			m_text.setString("0X");
			DisplayWindow::setAntiAlias(0);
			m_selection = 0;
			break;
		}
		break;
	}
}