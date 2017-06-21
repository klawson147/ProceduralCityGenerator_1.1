#include "FontManager.h"

FontManager::FontManager()
{
	addResource(FontName::sf_atarian_system, "resources\\fonts\\SF_Atarian_System.ttf");
}

FontManager::~FontManager()
{
}

const sf::Font& FontManager::get(FontName name) const
{
	return m_font.at(name);
}

void FontManager::addResource(FontName name, const std::string& filePath)
{
	sf::Font font;
	font.loadFromFile(filePath);

	m_font.insert(std::make_pair(name, font));
}