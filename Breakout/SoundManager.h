#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class SoundManager
	{
	private:
		sf::SoundBuffer paddleBuffer;
		sf::SoundBuffer wallBuffer;
		sf::SoundBuffer brickDamageBuffer;
		sf::SoundBuffer brickKillBuffer;
		sf::SoundBuffer loseLifeBuffer;
		sf::SoundBuffer levelBuffer;
		sf::SoundBuffer gameOverBuffer;

		sf::Sound paddleSFX;
		sf::Sound wallSFX;
		sf::Sound brickDamageSFX;
		sf::Sound brickKillSFX;
		sf::Sound loseLifeSFX;
		sf::Sound levelSFX;
		sf::Sound gameOverSFX;
		
	public:
		SoundManager();
		~SoundManager();
		void loadSounds();
		void playSound(int sound);
	};
}

#endif