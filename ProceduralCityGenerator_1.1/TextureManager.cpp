#include "TextureManager.h"

TextureManager::TextureManager()
{
	addResource(TextureName::menu_background, "resources\\img\\menu_background.png");
	addResource(TextureName::sfml_logo, "resources\\img\\sfml_logo.png");
	addResource(TextureName::sfml_logo_small, "resources\\img\\sfml_logo_small.png");
	addResource(TextureName::skyline1920, "resources\\img\\skyline1920.png");
}