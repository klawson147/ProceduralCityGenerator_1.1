#pragma once

#include <SFML\Graphics.hpp>
#include <map>
#include "ResourceManager.h"

enum class TextureName
{
	menu_background,
	sfml_logo,
	sfml_logo_small,
	skyline1920
};

class TextureManager :
	public ResourceManager<TextureName, sf::Texture>
{
public:
	TextureManager();
	
protected:
	void addResource(TextureName, const std::string);


};
