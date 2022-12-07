#include "UIManager.h"

using namespace gm;
using namespace sf;

UIManager::UIManager() {
	UIReset();
	load();
}

UIManager::~UIManager() {

}

void UIManager::UIReset() {
	gameOver = false;
	scoreText.setPosition(Vector2f(20, 20));
	scoreText.setFont(font);
	scoreText.setString("Score: 0");
	livesText.setPosition(Vector2f(20, 584));
	livesText.setFont(font);
	livesText.setString("Lives Remaining: 5");
	levelText.setPosition(Vector2f(940, 20));
	levelText.setFont(font);
	levelText.setString("Level: 1");
	gameOverText.setPosition(Vector2f(400, 300));
	gameOverText.setCharacterSize(48);
	gameOverText.setFont(font);
	gameOverText.setString("");
}

void UIManager::load() {
	font.loadFromFile("arial.ttf");
}

void UIManager::render(RenderWindow& window) {
	window.draw(scoreText);
	window.draw(livesText);
	window.draw(levelText);
	window.draw(gameOverText);
}

void UIManager::setScoreText(int score) {
	scoreText.setString("Score: " + std::to_string(score));
}

void UIManager::setLivesText(int lives) {
	livesText.setString("Lives Remaining: " + std::to_string(lives));
}

void UIManager::setLevelText(int level) {
	levelText.setString("Level: " + std::to_string(level));
}

void UIManager::setGameOver() {
	gameOverText.setString("GAME OVER");
}