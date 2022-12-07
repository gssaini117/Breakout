#include "Level.h"

using namespace gm;
using namespace sf;
using namespace std;

Level::Level() {
	bricks = new Brick[BRICK_COUNT];
	currLevel = 0;
	levelReset();
}

Level::~Level() {
	delete[] bricks;
}

void Level::update(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < BRICK_COUNT; i++)
	{
		bricks[i].update(window, deltaTime);
	}
}

void Level::render(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < BRICK_COUNT; i++)
	{
		bricks[i].render(window, deltaTime);
	}
}

const Brick* Level::getBricks() {
	return bricks;
}

void Level::levelReset() { // loads up level

	ifstream level("level" + to_string(currLevel) + ".txt");
	
	// read level with a while loop
}

int Level::getCurrLevel() {
	return currLevel + 1;
}

bool Level::isLevelBeaten() {
	for (int i = 0; i < BRICK_COUNT; i++) {
		if (!bricks[i].isDead())
			return false;
	}
	currLevel++;
	currLevel %= 3;
	return true;
}