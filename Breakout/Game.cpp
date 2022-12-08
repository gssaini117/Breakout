#include "Game.h"

using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() :  window(VideoMode(GameWidth, GameHeight), "Game"), 
				clock(), deltaTime(0), gameState(true),
				soundManager(), uiManager(), level(),
				playerScore(0), playerLives(5), currLevel(1),
				ball(Vector2f(530, 540), Vector2f(20,20)), 
				player(Vector2f(540, 560), Vector2f(180, 20)), 
				leftWall(Vector2f(-10, 0), Vector2f(12, 640)),
				rightWall(Vector2f(1078, 0), Vector2f(12, 640)),
				topWall(Vector2f(0, -10), Vector2f(1080, 12)),
				bottomWall(Vector2f(0, 638), Vector2f(1080, 12))
{
	window.setFramerateLimit(60);
}

void Game::run() {
	std::cout << "GAME BEGIN" << std::endl << std::endl;
	while (window.isOpen())
	{
		// Every frame we keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();

		handleInput();
		update();
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {

	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

		if (gameState) {
			// Player control
			player.setPosition(Vector2f(Mouse::getPosition(window).x - 90, 560));
			if (Mouse::getPosition(window).x < 90)
				player.setPosition(Vector2f(0, 560));
			if (Mouse::getPosition(window).x > 990)
				player.setPosition(Vector2f(900, 560));
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				ball.launchBall();
				soundManager.playSound(0);
			}
		}
		else {
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) window.close();
		}
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	if (gameState) {
		ball.update(window, deltaTime);
		player.update(window, deltaTime);
		level.update(window, deltaTime);

		// collision handling
		if (ball.collide(player.getCollider())) {
			ball.bounce(1);
			soundManager.playSound(0);
		}
		if (ball.collide(topWall.getCollider())) {
			ball.bounce(2);
			soundManager.playSound(1);
		}
		if (ball.collide(leftWall.getCollider()) || ball.collide(rightWall.getCollider())) {
			ball.bounce(3);
			soundManager.playSound(1);
		}
		if (ball.collide(bottomWall.getCollider())) {
			ball.bounce(3);
			ball.resetBall();
			soundManager.playSound(4);
			playerLives--;
			uiManager.setLivesText(playerLives);
		}
		for (int i = 0; i < 45; i++) {
			if (ball.collide(level.getBricks()[i].getCollider())) {
				ball.bounce(2);
				level.getBricks()[i].hit();
				if (level.getBricks()[i].isDead()) {
					soundManager.playSound(3);
					playerScore += 100;
					uiManager.setScoreText(playerScore);
				}
				else {
					soundManager.playSound(2);
				}
			}
		}
		

		// level handling
		if (level.isLevelBeaten()) {
			level.levelReset();
			ball.increaseBaseSpeed();
			ball.resetBall();
			uiManager.setLevelText(level.getCurrLevel());
			soundManager.playSound(5);
		}

		// loss condition
		if (playerLives == 0) {
			gameState = false;
			soundManager.playSound(6);
			uiManager.setGameOver();
		}
	}
	else {

	}
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	window.clear();

	ball.render(window, deltaTime);
	player.render(window, deltaTime);
	uiManager.render(window);
	level.render(window, deltaTime);

	window.display();
}

// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}