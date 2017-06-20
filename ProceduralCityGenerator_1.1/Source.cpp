#include "Engine.h"

int main()
{
	Engine _Engine;

	// Initialize Engine
	if (!_Engine.Initialize())
		return 1;
	
	// Start Engine Loop
	if (!_Engine.Start())
		return 1;

	return 0;
}