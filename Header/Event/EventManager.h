#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

namespace Event
{
	class EventManager
	{
	public:
		void pollEvents(RenderWindow* game_window);

		bool isKeyPressed(sf::Keyboard::Key key);
		bool isLeftMouseButtonClicked();
	};
}