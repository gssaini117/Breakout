#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class UIManager
	{
	private:
		sf::Font font;
		sf::Text scoreText;
		sf::Text livesText;
		sf::Text levelText;
		sf::Text gameOverText;
		bool gameOver;
	public:
		UIManager();
		~UIManager();
		void UIReset();
		void load();
		void render(sf::RenderWindow& window);
		void setScoreText(int score);
		void setLivesText(int lives);
		void setLevelText(int level);
		void setGameOver();
	};
}

#endif