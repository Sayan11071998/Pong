#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"

using namespace sf;
using namespace Core;
using namespace Event;

int main()
{
	GameWindowManager* game_window_manager = new GameWindowManager();
	EventManager* event_manager = new EventManager();
	
	game_window_manager->initialize();

	while (game_window_manager->isGameRunning())
	{
		event_manager->pollEvents(game_window_manager->getGameWindow());
		game_window_manager->update();
		game_window_manager->render();
	}

	return 0;
}