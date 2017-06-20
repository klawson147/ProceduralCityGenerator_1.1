#pragma once

#include <SFML\Graphics.hpp>
#include <map>

enum class TextureName
{
	menu_background,
	sfml_logo,
	sfml_logo_small,
	skyline1920
};

class TextureManager
{
public:
	TextureManager();

	const sf::Texture& get(TextureName) const;

private:

	void addResource(TextureName, const std::string&);

	std::map<TextureName, sf::Texture> m_texture;

};

