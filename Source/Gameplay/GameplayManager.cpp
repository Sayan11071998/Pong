#pragma once
#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(EventManager* manager) { event_manager = manager; }

	void GameplayManager::update()
	{
		player1->update(event_manager->isKeyPressed(Keyboard::W), event_manager->isKeyPressed(Keyboard::S));
		player2->update(event_manager->isKeyPressed(Keyboard::Up), event_manager->isKeyPressed(Keyboard::Down));
		ball->update(player1, player2);
	}

	void GameplayManager::render(RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
	}
}