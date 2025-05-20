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

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode({ 900, 413 }), "Trex", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(120);


    auto Image = sf::Image();
    Image.loadFromFile("pictures/icon.png");
    window.setIcon(Image.getSize(), Image.getPixelsPtr());

	sf::Music music("audio/Jurassic Park theme song..ogg");
	music.setVolume(50.0f);
	music.play();
	music.setLooping(true);
	music.setPlayingOffset(sf::seconds(30.0f));

	sf::SoundBuffer jump_buffer("audio/jump.ogg");
	sf::SoundBuffer point_buffer("audio/point.ogg");
	sf::SoundBuffer death_buffer("audio/die.ogg");
	sf::Sound jump_sound(jump_buffer);
	sf::Sound point_sound(point_buffer);
	point_sound.setVolume(25.0f);
	sf::Sound death_sound(death_buffer);

	sf::Clock clock;
	

    sf::Font font("arial.ttf");
    sf::Text score_text(font, "Score: 0");
    score_text.setFillColor(sf::Color::Black);
	score_text.setCharacterSize(30);
    score_text.setPosition({10.0f, 10.0f});

	sf::Text start_text(font, "Press ENTER to start");
	start_text.setFillColor(sf::Color::Black);
	start_text.setCharacterSize(60);
	start_text.setPosition({ 200.0f, 206.0f });

	sf::Text end_text(font);
	end_text.setFillColor(sf::Color::Black);
	end_text.setCharacterSize(60);
	end_text.setPosition({ 100.0f, 100.0f });

    Score score(score_text);

    sf::Texture TrexTextureIdle;
	sf::Texture TrexTextureRun;
	sf::Texture TrexTextureJump;
	sf::Texture TrexTextureDeath;
	sf::Texture ZiemiaTexture;
    sf::Texture CactusTexture;
	sf::Texture Ziemia2Texture;

    TrexTextureIdle.loadFromFile("olaf/base/idle.png");
	TrexTextureRun.loadFromFile("olaf/base/move.png");
	TrexTextureJump.loadFromFile("olaf/base/jump.png");
	TrexTextureDeath.loadFromFile("olaf/base/dead.png");
	ZiemiaTexture.loadFromFile("pictures/desertday.jpg");
	Ziemia2Texture.loadFromFile("pictures/desertnight.jpg");
	CactusTexture.loadFromFile("pictures/cactus.png");

	sf::Sprite Trex_sprite(TrexTextureIdle);
	Trex trex(Trex_sprite, TrexTextureIdle, TrexTextureRun, TrexTextureJump, TrexTextureDeath);
	trex.setTextureRect();
    trex.setOrigin();
	trex.setPosition(80, 300);
    trex.setScale(6.0f, 6.0f);

	background Ziemia(ZiemiaTexture);
    background Ziemia2(ZiemiaTexture);
	Ziemia.setPosition(0.0f, 0.0f);
	Ziemia2.setPosition(1440.0f, 0.0f);

	Cactus cactus(CactusTexture);
	cactus.setPosition(900.0f, 325.0f);
	Cactus cactus2(CactusTexture);
	cactus2.setPosition(950.0f, 325.0f);
	Cactus cactus3(CactusTexture);
	cactus3.setPosition(1500.0f, 325.0f);

	std::filesystem::path path = "highscores.txt";
	std::ofstream file(path, std::ios::app);

	float multiplier = 1.0f;
    int frames = 0;
	bool start = false;
	bool death = false;
	float time_to_switch = 0.0f;
	

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

		window.clear();
		Ziemia.draw(window);
		Ziemia2.draw(window);

		float deltaTime = clock.restart().asSeconds();

		trex.update(deltaTime);
		
		if (death) {
			time_to_switch += deltaTime;
			if (score.getScore() == 69)
			{
				music.setVolume(100.0f);
			}
			if (time_to_switch > 0.5f) {
					trex.setTexture(1);
					Ziemia.setPosition(0.0f, 0.0f);
					Ziemia2.setPosition(1440.0f, 0.0f);
					cactus.setPosition(900.0f, 325.0f);
					cactus2.setPosition(1400.0f, 325.0f);
					cactus3.setPosition(1900.0f, 325.0f);
					trex.setPosition(80.0f, 300.0f);
					death = false;
				time_to_switch = 0.0f;
			}
		}

		if (!start) {
			window.draw(start_text);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !death) {
				start = true;
				score.reset();
			}
			if (death) {
				end_text.setString("Your Score: " + std::to_string(score.getScore()));
				window.draw(end_text);
				multiplier = 1.0f;
			}
		}

		if (start) {
			++frames;
			std::cout << frames << std::endl;

			if (multiplier < 2.5) {
				if ((frames % 500) == 0) {
					multiplier += 0.15f;
				}
			}
			else {
				std::cout << "Max speed reached" << std::endl;
				std::cout << "Max speed reached" << std::endl;
				std::cout << "Max speed reached" << std::endl;
				std::cout << "Max speed reached" << std::endl;
			}

			Ziemia.move(multiplier);
			Ziemia2.move(multiplier);
			cactus.move(multiplier);
			cactus2.move(multiplier);
			cactus3.move(multiplier);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
				trex.jump();
				jump_sound.play();
				trex.setTexture(3);

			}

			if (Ziemia.getPosition().x + 1440.0f < 0) {
				Ziemia.setPosition(Ziemia2.getPosition().x + 1440.0f, 0.0f);
			}
			if (Ziemia2.getPosition().x + 1440.0f < 0) {
				Ziemia2.setPosition(Ziemia.getPosition().x + 1440.0f, 0.0f);
			}

			trex.applyGravity();
			score.update(multiplier, point_sound);

			Collider::checkCollision(trex, cactus.getGlobalBounds(), death, start, death_sound);
			Collider::checkCollision(trex, cactus2.getGlobalBounds(), death, start, death_sound);
			Collider::checkCollision(trex, cactus3.getGlobalBounds(), death, start, death_sound);
		}
    
		trex.draw(window);
		score.draw(window);
		cactus.draw(window);
		cactus2.draw(window);
		cactus3.draw(window);
        window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
			music.stop();
			score.reset();
			std::time_t now = std::time(nullptr);
			std::tm local_time;
			localtime_s(&local_time, &now);
			
			if (file) {
				file << std::put_time(&local_time,"%d/%m/%Y %H:%M:%S") << " | Highscore: " << score.getHighScore();
				file << std::endl;
				file.close();
			}
		}
    }
}