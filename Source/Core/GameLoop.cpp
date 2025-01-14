#include "../../Header/Core/GameLoop.h"

namespace Core
{
	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		gameplay_manager = new GameplayManager();

		game_window_manager->initialize();
	}

	void GameLoop::update()
	{
	}

	void GameLoop::render()
	{
		game_window_manager->clearGameWindow();
		game_window_manager->displayGameWindow();
		gameplay_manager->render(game_window_manager->getGameWindow());
	}

	bool GameLoop::isGameRunning() { return game_window_manager->isGameRunning(); }

	void GameLoop::pollEvent() { event_manager->pollEvents(game_window_manager->getGameWindow()); }
}