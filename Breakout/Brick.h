#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "GameObject.h"

namespace gm {
	class Brick : public GameObject
	{
	protected:
		int hp;
		sf::RectangleShape body;
	public:
		Brick();
		~Brick();
		void GenerateBrick(sf::Vector2f position, int type);
		virtual void update(sf::RenderWindow& window, float deltaTime) override;
		virtual void render(sf::RenderWindow& window, float deltaTime) override;
		virtual void setPosition(const sf::Vector2f& position) override;
		void setHealth(int health);
		void hit();
		bool isDead() const;
	};
}

#endif