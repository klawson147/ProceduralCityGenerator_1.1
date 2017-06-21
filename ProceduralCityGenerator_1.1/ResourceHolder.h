#pragma once

#include "FontManager.h"
#include "TextureManager.h"

struct ResourceHolder
{

public:

	static const ResourceHolder& get();

	const sf::Texture&	getTexture	(TextureName)	const;
	const sf::Font&		getFont		(FontName)		const;


private:
	FontManager		fonts;
	TextureManager	textures;


};