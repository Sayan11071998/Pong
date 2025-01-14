#include "../../Header/Event/EventManager.h"

namespace Event
{
	void EventManager::pollEvents(RenderWindow* game_window)
	{
		sf::Event event;
		
		while (game_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { game_window->close(); }
			if (isKeyPressed(sf::Keyboard::Escape)) { game_window->close(); }
		}
	}

	bool EventManager::isKeyPressed(Keyboard::Key key) { return Keyboard::isKeyPressed(key); }
}