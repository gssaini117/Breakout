#include "Brick.h"

using namespace gm;
using namespace sf;

Brick::Brick() : GameObject(Vector2f(0, 90), Vector2f(72, 18)) {
	body.setSize(Vector2f(72, 18));
	hp = 0;
}

Brick::~Brick() {

}

void Brick::GenerateBrick(Vector2f position, int health) {
	this->setPosition(position);
	this->setHealth(health);
}

void Brick::update(sf::RenderWindow& window, float deltaTime) {
	if (hp == 3) body.setFillColor(Color::Blue);
	if (hp == 2) body.setFillColor(Color::Green);
	if (hp == 1) body.setFillColor(Color::Yellow);
	if (hp == 0) body.setFillColor(Color::Black);
}

void Brick::render(sf::RenderWindow& window, float deltaTime) {
	window.draw(body);
}

void Brick::setPosition(const sf::Vector2f& position) {
	GameObject::setPosition(position);
	body.setPosition(position);
}

void Brick::setHealth(int health) {
	hp = health;
}

void Brick::hit() {
	hp--;
}

bool Brick::isDead() const {
	return hp <= 0;
}
