#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Gameplay
{
	class Ball
	{
	public:
		Ball();
		void update();
		void render(RenderWindow* game_window);

	private:
		CircleShape ball_sprite;
		const float radius = 10.0f;
		const float position_x = 615.0f;
		const float position_y = 335.0f;
	};
}