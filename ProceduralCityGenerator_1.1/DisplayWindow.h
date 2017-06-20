#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

namespace DisplayWindow
{
	void Init();
	void Clear();
	void Render();
	void checkWindowEvents();
	bool isOpen();
}
