#include "DisplayWindow.h"


DisplayWindow::DisplayWindow()
{

}

void DisplayWindow::Init()
{
	m_p_renderWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Procedural City Generator", sf::Style::Close);
}

void DisplayWindow::Render()
{
	m_p_renderWindow->display();
}
void DisplayWindow::Clear()
{
	m_p_renderWindow->clear(sf::Color::Black);
}

void DisplayWindow::checkWindowEvents()
{
	sf::Event _event;

	while (m_p_renderWindow->pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::Closed:
			closeWindow();
			break;
		}
	}

}
bool DisplayWindow::isOpen()
{
	return m_p_renderWindow->isOpen();
}

void DisplayWindow::closeWindow()
{
	m_p_renderWindow->close();
	delete m_p_renderWindow;
}

void DisplayWindow::resizeWindow(sf::Vector2f size)
{
	delete m_p_renderWindow;
	m_p_renderWindow = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Procedural City Generator", sf::Style::Close);
}
