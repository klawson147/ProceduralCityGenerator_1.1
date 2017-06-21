#include "ResourceHolder.h"

// Singleton Pattern
const ResourceHolder& ResourceHolder::get()
{
	static ResourceHolder holder;
	return holder;
}

const sf::Texture& ResourceHolder::getTexture(TextureName name) const
{
	const sf::Texture& texture = textures.get(name);
	return textures.get(name);
}

const sf::Font& ResourceHolder::getFont(FontName name) const
{
	return fonts.get(name);
}