#include "Ball.h"
#include "Random.h"

using namespace sf;
using namespace gm;

Ball::Ball(const Vector2f& position, const Vector2f& size) : GameObject(position, size) {
	body.setPosition(position);
	body.setSize(size);
	body.setFillColor(Color::Red);
	baseSpeed = 180;
	resetBall();
}

void Ball::update(sf::RenderWindow& window, float deltaTime) {
	if (reset) {
		this->setPosition(Vector2f(Mouse::getPosition(window).x-10, 540));
		if (Mouse::getPosition(window).x < 90)
			this->setPosition(Vector2f(80, 540));
		if (Mouse::getPosition(window).x > 990)
			this->setPosition(Vector2f(980, 540));
	}
	else 
		move(Vector2f(BallMovementSpeedPerSecond * MovementDirection.x * deltaTime, BallMovementSpeedPerSecond * MovementDirection.y * deltaTime));
}

void Ball::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Ball::setPosition(const Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Ball::move(const Vector2f& velocity) {
	GameObject::move(velocity);
	body.setPosition(position);
}

void Ball::setMovmentDirection(sf::Vector2f direction) {
	MovementDirection = direction;
}

sf::Vector2f Ball::getMovementDirection() const {
	return MovementDirection;
}


const Color& Ball::getFillColor() const {
	return body.getFillColor();
}

void Ball::setFillColor(const Color& color) {
	body.setFillColor(color);
}

int Ball::getCurrSpeed() {
	return BallMovementSpeedPerSecond;
}

void Ball::setCurrSpeed(int speed) {
	BallMovementSpeedPerSecond = speed;
}

void Ball::bounce(int type) {
	switch (type) {
	case 1: // paddle collision
		BallMovementSpeedPerSecond += 20;
		MovementDirection = Vector2f(MovementDirection.x, -MovementDirection.y);
		break;
	case 2: // top wall collision
		MovementDirection = Vector2f(MovementDirection.x, -MovementDirection.y);
		break;
	case 3: // left/right wall collision
		MovementDirection = Vector2f(-MovementDirection.x, MovementDirection.y);
		break;
	}
}

void Ball::increaseBaseSpeed() {
	baseSpeed += 20;
}

void Ball::resetBall() {
	reset = true;
	BallMovementSpeedPerSecond = baseSpeed;
	MovementDirection = Vector2f(Random::Range(-0.6f, 0.6f), -1);
}

void Ball::launchBall() {
	reset = false;
}