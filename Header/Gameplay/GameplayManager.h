#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Ball/Ball.h"
#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay
{
	class GameplayManager
	{
	public:
		GameplayManager(EventManager* manager);

		void update();
		void render(RenderWindow* game_window);

	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		EventManager* event_manager;

		void initialize();
	};
}