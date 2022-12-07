#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <string>
#include "Brick.h"

namespace gm {
	class Level
	{
	private:
		Brick* bricks;
		int currLevel;
		int BRICK_COUNT = 45;
	public: 
		Level();
		~Level();
		void update(sf::RenderWindow& window, float deltaTime);
		void render(sf::RenderWindow& window, float deltaTime);
		const Brick* getBricks();
		void levelReset();
		int getCurrLevel();
		bool isLevelBeaten();
	};
}

#endif