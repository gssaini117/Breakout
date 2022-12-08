#include "Level.h"

using namespace gm;
using namespace sf;
using namespace std;

Level::Level() {
	bricks = new Brick[BRICK_COUNT];
	currLevel = 2;
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

Brick* Level::getBricks() {
	return bricks;
}

void Level::levelReset() { // loads up level

	ifstream level("level" + to_string(currLevel) + ".txt");
	int brickCounter = 0;
	Vector2f position = Vector2f(0, 90);
	string temp = "";
	if (level.is_open()) {
		while (brickCounter < BRICK_COUNT) {
			
			level >> temp;

			if (position.x >= 1080) {
				position.x = 0;
				position.y += 18;
			}

			if (temp == "-") {
				position.x += 72;
				continue;
			}

			bricks[brickCounter].GenerateBrick(position, stoi(temp));
			position.x += 72;
			brickCounter++;
		}
	}
	level.close();
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