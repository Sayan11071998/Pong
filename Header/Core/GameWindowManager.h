#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Core
{
	class GameWindowManager
	{
	public:
		void initialize();
		void update();
		void render();

		bool isGameRunning();
		void clearGameWindow();
		void displayGameWindow();

		RenderWindow* getGameWindow();

	private:
		int game_window_width = 1280;
		int game_window_height = 720;
		std::string game_title = "Pong";

		RenderWindow* game_window;

		void createGameWindow();
	};
}