#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"

using namespace sf;
using namespace Core;

int main()
{
	Core::GameWindowManager gameWindowManager;

	gameWindowManager.initialize();

	while (gameWindowManager.isGameRunning()) { gameWindowManager.render(); }

	return 0;
}