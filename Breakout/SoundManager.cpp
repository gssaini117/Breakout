#include "SoundManager.h"

using namespace sf;
using namespace gm;

SoundManager::SoundManager() {
	loadSounds();
}

SoundManager::~SoundManager() {

}

void SoundManager::loadSounds() {
	paddleBuffer.loadFromFile("Paddle.wav");
	wallBuffer.loadFromFile("Wall.wav");
	brickDamageBuffer.loadFromFile("BrickDamage.wav");
	brickKillBuffer.loadFromFile("BrickKill.wav");
	loseLifeBuffer.loadFromFile("LoseLife.wav");
	levelBuffer.loadFromFile("Level.wav");
	gameOverBuffer.loadFromFile("GameOver.wav");

	paddleSFX.setBuffer(paddleBuffer);
	wallSFX.setBuffer(wallBuffer);
	brickDamageSFX.setBuffer(brickDamageBuffer);
	brickKillSFX.setBuffer(brickKillBuffer);
	loseLifeSFX.setBuffer(loseLifeBuffer);
	levelSFX.setBuffer(levelBuffer);
	gameOverSFX.setBuffer(gameOverBuffer);
}

void SoundManager::playSound(int sound) {
	switch (sound) {
	case 0:
		paddleSFX.play();
		break;
	case 1:
		wallSFX.play();
		break;
	case 2:
		brickDamageSFX.play();
		break;
	case 3:
		brickKillSFX.play();
		break;
	case 4:
		loseLifeSFX.play();
		break;
	case 5:
		levelSFX.play();
		break;
	case 6:
		gameOverSFX.play();
		break;
	}
}