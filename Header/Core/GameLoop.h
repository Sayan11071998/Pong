#pragma once
#include "SFML/Graphics.hpp"
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"

using namespace sf;
using namespace std;
using namespace Core;
using namespace Event;
using namespace Gameplay;

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
		GameplayManager* gameplay_manager;
	};
}