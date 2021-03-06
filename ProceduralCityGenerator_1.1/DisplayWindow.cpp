#include "DisplayWindow.h"

sf::RenderWindow* m_p_renderWindow;
namespace DisplayWindow
{
	sf::ContextSettings m_context;
	sf::RenderWindow* m_p_renderWindow;

	void Init()
	{
		m_context.antialiasingLevel = 0;
		m_p_renderWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "Procedural City Generator", sf::Style::Close, m_context);
		m_p_renderWindow->setIcon(sfml_icon.width, sfml_icon.height, sfml_icon.pixel_data);
	}

	void Render()
	{
		m_p_renderWindow->display();
	}
	void Clear()
	{
		m_p_renderWindow->clear(sf::Color::White);
	}

	void setSize(sf::Vector2u size)
	{
		m_p_renderWindow->create(sf::VideoMode(size.x, size.y), "Procedural City Generator", sf::Style::Close, m_context);
	}

	void setAntiAlias(int val)
	{
		sf::Vector2u size = m_p_renderWindow->getSize();
		m_context.antialiasingLevel = val;
		m_p_renderWindow->create(sf::VideoMode(size.x, size.y), "Procedural City Generator", sf::Style::Close, m_context);
	}

	int getAntiAlias()
	{
		return m_context.antialiasingLevel;
	}

	sf::RenderWindow* getRenderWindow()
	{
		return m_p_renderWindow;
	}

	bool isOpen()
	{
		return m_p_renderWindow->isOpen();
	}

	void Draw(sf::Drawable& element)
	{
		m_p_renderWindow->draw(element);
	}

	sf::Vector2u getSize()
	{
		return m_p_renderWindow->getSize();
	}

	void Close()
	{
		m_p_renderWindow->close();
	}

	// Redo?
	sf::Vector2f getRelativePosition(DisplayWindowPosition position, sf::Vector2f size, sf::Vector2f offset)
	{
		sf::Vector2f newPosition;

		switch (position)
		{
		case DisplayWindowPosition::top_left:
			newPosition.x = WINDOW_MARGIN + offset.x;
			newPosition.y = WINDOW_MARGIN - (size.y / 2) + offset.y;
			return newPosition;

		case DisplayWindowPosition::top_center:
			newPosition.x = (m_p_renderWindow->getSize().x / 2) - (size.x / 2) + offset.x;
			newPosition.y = WINDOW_MARGIN - (size.y / 2) + offset.y;
			return newPosition;

		case DisplayWindowPosition::top_right:
			newPosition.x = m_p_renderWindow->getSize().x - size.x - WINDOW_MARGIN + offset.x;
			newPosition.y = WINDOW_MARGIN - (size.y / 2) + offset.y;
			return newPosition;

		case DisplayWindowPosition::center_left:
			newPosition.x = WINDOW_MARGIN + offset.x;
			newPosition.y = (m_p_renderWindow->getSize().y / 2) - (size.y / 2) + offset.y;
			return newPosition;

		case DisplayWindowPosition::center_center:
			newPosition.x = (m_p_renderWindow->getSize().x / 2) - (size.x / 2) + offset.x;
			newPosition.y = (m_p_renderWindow->getSize().y / 2) - (size.y / 2) + offset.y;
			return newPosition;

		case DisplayWindowPosition::center_right:
			newPosition.x = m_p_renderWindow->getSize().x - size.x - WINDOW_MARGIN + offset.x;
			newPosition.y = (m_p_renderWindow->getSize().y / 2) - (size.y / 2) + offset.y;
			return newPosition;

		case DisplayWindowPosition::bottom_left:
			newPosition.x = WINDOW_MARGIN + offset.x;
			newPosition.y = ((m_p_renderWindow->getSize().y - size.y) - WINDOW_MARGIN) + offset.y;
			return newPosition;
		}
	}
}