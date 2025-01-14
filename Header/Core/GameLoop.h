#pragma once
#include "SFML/Graphics.hpp"
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"

using namespace sf;
using namespace Core;
using namespace Event;
using namespace std;

namespace Core
{
	class GameLoop
	{
	public:
		void initialize();
		void update();
		void render();

		bool isGameRunning();
		void pollEvent();

	private:
		GameWindowManager* game_window_manager;
		EventManager* event_manager;
	};
}