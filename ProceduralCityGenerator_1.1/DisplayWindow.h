#include <iostream>
#pragma once
class DisplayWindow
{
public:

	void Init();
	void Clear();
	void Render();
	void checkWindowEvents();
	bool isOpen();

	DisplayWindow();
	~DisplayWindow();
};

