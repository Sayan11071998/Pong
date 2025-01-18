#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle/Paddle.h"
#include "../../Header/Utility/TimeService.h"

using namespace sf;
using namespace std;
using namespace Utility;

namespace Gameplay
{
	enum class BallState
	{
		Idle,
		Moving
	};

	class Ball
	{
	public:
		Ball();

		void onCollision(Paddle* player1, Paddle* player2);
		void update(Paddle* player1, Paddle* player2, TimeService* timeService);
		void render(RenderWindow* game_window);

		void move(TimeService* timeService);

		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoundaryCollision();
		void handleOutofBoundCOllision();

	private:
		Texture pong_ball_texture;
		Sprite pong_ball_sprite;

		string texture_path = "Assets/Textures/Ball.png";

		const float scale_x = 0.06f;
		const float scale_y = 0.06f;

		const float position_x = 615.0f;
		const float position_y = 335.0f;

		const float ball_speed = 0.5f;
		const float speed_multiplier = 100.0f;

		Vector2f velocity;

		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;
		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;

		float delay_duration = 2.0f;
		float elapsed_delay_time = 0.0f;
		BallState current_state = BallState::Idle;

		void loadTexture();
		void initializeVariables();
		void updateDelayTime(float deltaTime);
		void reset();
	};
}