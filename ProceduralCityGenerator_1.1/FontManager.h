#pragma once

#include <SFML\Graphics.hpp>
#include <map>
enum class FontName
{
	sf_atarian_system
};

class FontManager
{
public:
	FontManager();
	~FontManager();

	const sf::Font& get(FontName) const;

private:

	void addResource(FontName, const std::string&);

	std::map<FontName, sf::Font> m_font;

};

