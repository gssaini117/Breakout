#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

#include "Ball.h"
#include "Paddle.h"
#include "SoundManager.h"
#include "UIManager.h"

namespace gm {
	const int GameWidth = 1080;
	const int GameHeight = 640;

	class Game {
	private:
		sf::RenderWindow window;
		sf::Clock clock;
		float deltaTime;
		bool gameState;

		SoundManager soundManager;
		UIManager uiManager;

		int playerScore;
		int playerLives;
		int currLevel;
		
		Ball ball;
		Paddle leftWall;
		Paddle rightWall;
		Paddle topWall;
		Paddle bottomWall;
		Paddle player;

	public:
		Game();
		void run();
		void handleInput();
		void update();
		void render();
		~Game();
	};
}

#endif