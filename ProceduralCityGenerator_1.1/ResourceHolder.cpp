#include "ResourceHolder.h"

// Singleton Pattern
const ResourceHolder& ResourceHolder::get()
{
	static ResourceHolder holder;
	return holder;
}

const sf::Texture& ResourceHolder::getTexture(TextureName name) const
{
	return textures.get(name);
}

const sf::Font& ResourceHolder::getFont(FontName name) const
{
	return fonts.get(name);
}