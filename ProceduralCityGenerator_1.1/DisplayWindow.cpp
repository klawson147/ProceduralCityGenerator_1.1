#include "DisplayWindow.h"


DisplayWindow::DisplayWindow()
{

}

void DisplayWindow::Init()
{
	std::cout << "Window Init\n";
}

void DisplayWindow::Render()
{
	std::cout << "Window Render\n";
}
void DisplayWindow::Clear()
{
	std::cout << "Window Clear\n";
}

void DisplayWindow::checkWindowEvents()
{
	std::cout << "Window Check Event\n";
}
bool DisplayWindow::isOpen()
{
	return true;
}


