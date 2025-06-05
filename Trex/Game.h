#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Trex.h"
#include "background.h"
#include "Score.h"
#include "Collider.h"
#include "Cactus.h"
#include <filesystem>
#include <fstream>
#include <ctime>
#include <iomanip>

class Game
{
public:
	Game(sf::Texture Trex_Idle_Texture, sf::Font font, sf::SoundBuffer jump_buffer, sf::SoundBuffer point_buffer, sf::SoundBuffer death_buffer, sf::Texture desertTexture);
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void reset();
	
	void loadResources();
	void setUp();
	void saveHighscore();
	
	sf::RenderWindow window;
	sf::Font font;
	sf::Text scoreText, startText, endText, highScoreText;
	sf::Music music;
	sf::SoundBuffer jumpBuffer, pointBuffer, deathBuffer;
	sf::Sound jumpSound, pointSound, deathSound;
	Score score;
	Trex trex;
	Background ziemia1, ziemia2;
	std::vector<Cactus> cacti;
	sf::Clock clock;
	float multiplier = 1.0f;
	int frames = 0;
	bool start = false;
	bool death = false;
	float timeToSwitch = 0.0f;
};
/*
#include "Game.h"

int main() {

	sf::Texture trexIdleTexture;
	trexIdleTexture.loadFromFile("olaf/base/idle.png");

	sf::Font font("arial.ttf");

	sf::SoundBuffer jumpBuffer;
	jumpBuffer.loadFromFile("audio/jump.ogg");
	sf::SoundBuffer pointBuffer;
	pointBuffer.loadFromFile("audio/point.ogg");
	sf::SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("audio/die.ogg");

	sf::Texture desertTexture;
	desertTexture.loadFromFile("pictures/desertday.jpg");

	Game game(trexIdleTexture, font, jumpBuffer, pointBuffer, deathBuffer, desertTexture);
	game.run();
	return 0;

}
*/
