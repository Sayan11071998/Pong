#pragma once
#include "../../Header/Gameplay/Ball/Ball.h"

namespace Gameplay
{
	using namespace std;

	Ball::Ball()
	{
		loadTexture();
		initializeVariables();
	}

	void Ball::onCollision(Paddle* player1, Paddle* player2)
	{
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutofBoundCollision();
	}

	void Ball::update(Paddle* player1, Paddle* player2, TimeService* timeService)
	{
		move(timeService);
		onCollision(player1, player2);
	}

	void Ball::render(RenderWindow* game_window) { game_window->draw(pong_ball_sprite); }

	void Ball::move(TimeService* timeService)
	{
		updateDelayTime(timeService->getDeltaTime());

		if (current_state == BallState::Moving)
			pong_ball_sprite.move(velocity * timeService->getDeltaTime() * speed_multiplier);
	}

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		const RectangleShape& player1Paddle = player1->getPaddleSprite();
		const RectangleShape& player2Paddle = player2->getPaddleSprite();

		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		FloatRect Player1PaddleBounds = player1Paddle.getGlobalBounds();
		FloatRect Player2PaddleBounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(Player1PaddleBounds) && velocity.x < 0)
		{
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
			velocity.x = -velocity.x;
		}

		if (ball_bounds.intersects(Player2PaddleBounds) && velocity.x > 0)
		{
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
			velocity.x = -velocity.x;
		}
	}

	void Ball::handleBoundaryCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.top <= top_boundary && velocity.y < 0)
		{
			velocity.y = -velocity.y;
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}

		if (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0)
		{
			velocity.y = -velocity.y;
			SoundManager::PlaySoundEffect(SoundType::BALL_BOUNCE);
		}
	}

	void Ball::handleOutofBoundCollision()
	{
		FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			updateLeftCollisionState(true);
			reset();
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			updateRightCollisionState(true);
			reset();
		}
	}

	bool Ball::isLeftCollisionOccurred() { return had_left_collision; }

	bool Ball::isRightCollisionOccurred() { return had_right_collision; }

	void Ball::updateLeftCollisionState(bool value) { had_left_collision = value; }

	void Ball::updateRightCollisionState(bool value) { had_right_collision = value; }

	void Ball::loadTexture() { pong_ball_texture.loadFromFile(texture_path); }

	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
		velocity = Vector2f(ball_speed, ball_speed);
	}

	void Ball::updateDelayTime(float deltaTime)
	{
		if (current_state == BallState::Idle)
		{
			elapsed_delay_time += deltaTime;

			if (elapsed_delay_time >= delay_duration)
				current_state = BallState::Moving;
			else
				return;
		}
	}

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(position_x, position_y);
		velocity = Vector2f(ball_speed, ball_speed);
		current_state = BallState::Idle;
		elapsed_delay_time = 0.0f;
	}
}