#pragma once
#include "../../Header/Gameplay/Ball/Ball.h"

namespace Gameplay
{
	Ball::Ball()
	{
		loadTexture();
		initializeVariables();
	}

	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutofBoundCOllision();
	}

	void Ball::update(Paddle* player1, Paddle* player2)
	{
		move();
		onCollision(player1, player2);
	}

	void Ball::render(RenderWindow* game_window) { game_window->draw(pong_ball_sprite); }

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();

		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		FloatRect Player1PaddleBounds = player1Paddle.getGlobalBounds();
		FloatRect Player2PaddleBounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(Player1PaddleBounds) && velocity.x < 0) { velocity.x = -velocity.x; }
		if (ball_bounds.intersects(Player2PaddleBounds) && velocity.x > 0) { velocity.x = -velocity.x; }
	}

	void Ball::handleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) || (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
			velocity.y = -velocity.y;
	}

	void Ball::handleOutofBoundCOllision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
			reset();
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
			reset();
	}

	void Ball::loadTexture() { pong_ball_texture.loadFromFile(texture_path); }

	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}

	void Ball::move() { pong_ball_sprite.move(velocity); }

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}
}