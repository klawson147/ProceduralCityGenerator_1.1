#pragma once
#include "ResourceManager.h"
#include <SFML\Graphics.hpp>
#include <map>
enum class FontName
{
	sf_atarian_system
};

class FontManager :
	public ResourceManager<FontName, sf::Font>
{
public:
	FontManager();


private:

};
