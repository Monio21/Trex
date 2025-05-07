#include <SFML/Graphics.hpp>
#include <iostream>
#include "Trex.h"
#include "background.h"
#include "Score.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 413 }), "Trex", sf::Style::Close | sf::Style::Resize);

    auto Image = sf::Image();
    Image.loadFromFile("icon.png");
    window.setIcon(Image.getSize(), Image.getPixelsPtr());

    sf::Font score_font("arial.ttf");
    sf::Text score_text(score_font, "Score: 0");
    score_text.setFillColor(sf::Color::Black);
	score_text.setCharacterSize(24);
    score_text.setPosition({10.0f, 10.0f});

    Score score(0.1f,score_text);

    sf::Texture TrexTextureIdle;
	sf::Texture TrexTextureRun;
	sf::Texture TrexTextureJump;
	sf::Texture TrexTextureDeath;
	sf::Texture ZiemiaTexture;

    TrexTextureIdle.loadFromFile("olaf/base/idle.png");
	TrexTextureRun.loadFromFile("olaf/base/move.png");
	TrexTextureJump.loadFromFile("olaf/base/jump.png");
	TrexTextureDeath.loadFromFile("olaf/base/dead.png");
	ZiemiaTexture.loadFromFile("desertday.jpg");

	sf::Sprite Trex_sprite(TrexTextureIdle);
	Trex trex(Trex_sprite, TrexTextureIdle, TrexTextureRun, TrexTextureJump, TrexTextureDeath);
	trex.setTextureRect();
    trex.setOrigin();
	trex.setPosition(200, 200);
    trex.setScale(4.0f, 4.0f);

	background Ziemia(ZiemiaTexture);
    background Ziemia2(ZiemiaTexture);
	Ziemia.setPosition(0.0f, 0.0f);
    Ziemia.setTexture();
	Ziemia2.setPosition(1440.0f, 0.0f);
    Ziemia2.setTexture();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

		trex.update(0.1f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ 
            Ziemia.move(-0.1f, 0.0f);
			Ziemia2.move(-0.1f, 0.0f);
			trex.setTexture(2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
          //  Ziemia.move({ 0.1f, 0.0f });
		  // Ziemia2.move({ 0.1f, 0.0f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            trex.move( 0.0f, -0.1);
			trex.setTexture(3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            trex.move( 0.0f, 0.1f);
        }
        if (Ziemia.getPosition().x + 1440.0f < 0){
			Ziemia.setPosition( Ziemia2.getPosition().x + 1440.0f, 0.0f );
        }
        if (Ziemia2.getPosition().x + 1440.0f < 0) {
            Ziemia2.setPosition(Ziemia.getPosition().x + 1440.0f, 0.0f );
        }
        window.clear();
		Ziemia.draw(window);
		Ziemia2.draw(window);
		trex.draw(window);
		score.update();
		score.draw(window);
        window.display();
    }
}