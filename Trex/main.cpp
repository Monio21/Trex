#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 413 }), "Trex", sf::Style::Close | sf::Style::Resize);

	auto Image = sf::Image();
	Image.loadFromFile("icon.png");
	window.setIcon(Image.getSize(), Image.getPixelsPtr());
    sf::Texture TrexTextureIdle;
	sf::Texture TrexTextureRun;
    TrexTextureIdle.loadFromFile("olaf/base/idle.png");
	TrexTextureRun.loadFromFile("olaf/base/move.png");

	sf::Sprite Trex(TrexTextureIdle);
	int frameWidth = 24;
    Trex.setTextureRect({ {0,0}, {24,24} });
    Trex.setOrigin({Trex.getTextureRect().size.x / 2.0f, Trex.getTextureRect().size.y / 2.0f });
	Trex.setPosition({ 200, 200 });
	Trex.setScale({ 4.0f, 4.0f });
	float timer = 0.0f;
	float switchTime = 15.0f;




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

		timer += 0.1f;
        if (timer >= switchTime) {

            frameWidth += 24;

			if (frameWidth >= TrexTextureIdle.getSize().x)
				frameWidth = 0; 

            if (frameWidth < TrexTextureIdle.getSize().x)
                Trex.setTextureRect({ {frameWidth , 0 }, {24, 24} });

			timer = 0.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ 
            Ziemia.move({ -0.1f, 0.0f });
			Ziemia2.move({ -0.1f, 0.0f });
			Trex.setTexture(TrexTextureRun);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            Ziemia.move({ 0.1f, 0.0f });
			Ziemia2.move({ 0.1f, 0.0f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            Trex.move({ 0.0f, -0.1f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            Trex.move({ 0.0f, 0.1f });
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
        window.draw(Trex);
        window.display();
    }
}