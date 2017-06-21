#include "DisplayWindow.h"

sf::RenderWindow* m_p_renderWindow;
namespace DisplayWindow
{
	sf::RenderWindow* m_p_renderWindow;

	void Init()
	{
		m_p_renderWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Procedural City Generator", sf::Style::Close);
	}

	void Render()
	{
		m_p_renderWindow->display();
	}
	void Clear()
	{
		m_p_renderWindow->clear(sf::Color::Black);
	}

	void checkWindowEvents()
	{
		sf::Event _event;

		while (m_p_renderWindow->pollEvent(_event))
		{
			switch (_event.type)
			{
			case sf::Event::Closed:
				m_p_renderWindow->close();
				break;
			}
		}
	}
	bool isOpen()
	{
		return m_p_renderWindow->isOpen();
	}

	void Draw(sf::Drawable& element)
	{
		m_p_renderWindow->draw(element);
	}

	sf::Vector2u getWindowSize()
	{
		return m_p_renderWindow->getSize();
	}
}