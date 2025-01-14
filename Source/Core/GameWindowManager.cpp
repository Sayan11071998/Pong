#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	void GameWindowManager::initialize()
	{
		game_window = new RenderWindow();
		createGameWindow();
	}

	void GameWindowManager::createGameWindow() { game_window->create(VideoMode(game_window_width, game_window_height), game_title); }

	bool GameWindowManager::isGameOpen() { return game_window->isOpen(); }

	void GameWindowManager::clearGameWindow() { game_window->clear(); }

	void GameWindowManager::displayGameWindow() { return game_window->display(); }

	RenderWindow* GameWindowManager::getGameWindow() { return game_window; }
}