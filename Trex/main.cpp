#include <SFML/Graphics.hpp>
#include <iostream>
#include "Trex.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 413 }), "Trex", sf::Style::Close | sf::Style::Resize);

	auto Image = sf::Image();
	Image.loadFromFile("icon.png");
	window.setIcon(Image.getSize(), Image.getPixelsPtr());
    sf::Texture TrexTextureIdle;
	sf::Texture TrexTextureRun;
	sf::Texture TrexTextureJump;
	sf::Texture TrexTextureDeath;
    TrexTextureIdle.loadFromFile("olaf/base/idle.png");
	TrexTextureRun.loadFromFile("olaf/base/move.png");
	TrexTextureJump.loadFromFile("olaf/base/jump.png");
	TrexTextureDeath.loadFromFile("olaf/base/dead.png");
	sf::Sprite Trex_sprite(TrexTextureIdle);
	Trex trex(Trex_sprite, TrexTextureIdle, TrexTextureRun, TrexTextureJump, TrexTextureDeath);
	trex.setTextureRect();
    trex.setOrigin();
	trex.setPosition(200, 200);
    trex.setScale(4.0f, 4.0f);

    sf::RectangleShape Ziemia(sf::Vector2f(1440.0f, 413.0f));
    sf::RectangleShape Ziemia2(sf::Vector2f(1440.0f, 413.0f));
    sf::Texture ZiemiaTexture;
    ZiemiaTexture.loadFromFile("desertday.jpg");
    Ziemia.setTexture(&ZiemiaTexture);
	Ziemia2.setTexture(&ZiemiaTexture);
	Ziemia2.setPosition({ 1440.0f, 0.0f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

		trex.update(0.1f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ 
            Ziemia.move({ -0.1f, 0.0f });
			Ziemia2.move({ -0.1f, 0.0f });
			trex.setTexture(2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            Ziemia.move({ 0.1f, 0.0f });
			Ziemia2.move({ 0.1f, 0.0f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            trex.move( 0.0f, -0.1);
			trex.setTexture(3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            trex.move( 0.0f, 0.1f);
        }
        if (Ziemia.getPosition().x + 1440.0f < 0){
			Ziemia.setPosition({ Ziemia2.getPosition().x + 1440.0f, 0.0f });
        }
        if (Ziemia2.getPosition().x + 1440.0f < 0) {
            Ziemia2.setPosition({ Ziemia.getPosition().x + 1440.0f, 0.0f });
        }

        window.clear();
        window.draw(Ziemia);
        window.draw(Ziemia2);
		trex.draw(window);
        window.display();
    }
}