#include <SFML/Graphics.hpp>
#include <iostream>
#include "Trex.h"
#include "background.h"
#include "Score.h"
#include "Collider.h"

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode({ 900, 413 }), "Trex", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(120);

    auto Image = sf::Image();
    Image.loadFromFile("icon.png");
    window.setIcon(Image.getSize(), Image.getPixelsPtr());


	sf::Clock clock;
	

    sf::Font font("arial.ttf");
    sf::Text score_text(font, "Score: 0");
    score_text.setFillColor(sf::Color::Black);
	score_text.setCharacterSize(30);
    score_text.setPosition({10.0f, 10.0f});

	sf::Text start_text(font, "Press SPACE to start");
	start_text.setFillColor(sf::Color::Black);
	start_text.setCharacterSize(60);
	start_text.setPosition({ 200.0f, 206.0f });

    Score score(4.0f,score_text);

    sf::Texture TrexTextureIdle;
	sf::Texture TrexTextureRun;
	sf::Texture TrexTextureJump;
	sf::Texture TrexTextureDeath;
	sf::Texture ZiemiaTexture;
    sf::Texture CactusTexture;

    TrexTextureIdle.loadFromFile("olaf/base/idle.png");
	TrexTextureRun.loadFromFile("olaf/base/move.png");
	TrexTextureJump.loadFromFile("olaf/base/jump.png");
	TrexTextureDeath.loadFromFile("olaf/base/dead.png");
	ZiemiaTexture.loadFromFile("desertday.jpg");
	CactusTexture.loadFromFile("cactus.png");

	sf::Sprite Trex_sprite(TrexTextureIdle);
	Trex trex(Trex_sprite, TrexTextureIdle, TrexTextureRun, TrexTextureJump, TrexTextureDeath);
	trex.setTextureRect();
    trex.setOrigin();
	trex.setPosition(80, 320);
    trex.setScale(6.0f, 6.0f);

	background Ziemia(ZiemiaTexture);
    background Ziemia2(ZiemiaTexture);
	Ziemia.setPosition(0.0f, 0.0f);
    Ziemia.setTexture();
	Ziemia2.setPosition(1440.0f, 0.0f);
    Ziemia2.setTexture();

	background cactus(CactusTexture);
	cactus.setRect(246.0f, 306.0f);
	cactus.setTexture();
	cactus.setScale(0.25f, 0.25f);
	cactus.setPosition(400.0f, 300.0f);

	float multiplier = 1.0f;
    int frames = 0;
	bool start = false;

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
		
		if (!start) {
			window.draw(start_text);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
				start = true;
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
			if (multiplier >= 2.5) {
				std::cout << "Max speed reached" << std::endl;
				std::cout << "Max speed reached" << std::endl;
				std::cout << "Max speed reached" << std::endl;
				std::cout << "Max speed reached" << std::endl;
			}

			Ziemia.move(multiplier);
			Ziemia2.move(multiplier);
			cactus.move(multiplier);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
				trex.jump();
				trex.setTexture(3);

			}

			if (Ziemia.getPosition().x + 1440.0f < 0) {
				Ziemia.setPosition(Ziemia2.getPosition().x + 1440.0f, 0.0f);
			}
			if (Ziemia2.getPosition().x + 1440.0f < 0) {
				Ziemia2.setPosition(Ziemia.getPosition().x + 1440.0f, 0.0f);
			}

			trex.applyGravity();
			score.update(multiplier);

			if (Collider::checkCollision(trex.getGlobalBounds(), cactus.getGlobalBounds())) {
				trex.setTexture(4);
				start = false;
			}
		}
    
		trex.draw(window);
		score.draw(window);
		cactus.draw(window);
        window.display();
    }
}