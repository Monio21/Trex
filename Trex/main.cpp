#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 512, 512 }), "Trex", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape Trex(sf::Vector2f(60.0f, 60.0f));
    Trex.setPosition({ 20.0f, 335.0f });
    sf::Texture TrexTexture;
    TrexTexture.loadFromFile("Trex_texture2.png");
    Trex.setTexture(&TrexTexture);
    
    sf::RectangleShape Ziemia(sf::Vector2f(512.0f, 512.0f));
    sf::Texture ZiemiaTexture;
    ZiemiaTexture.loadFromFile("ground_texture.jpg");
    Ziemia.setTexture(&ZiemiaTexture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            Trex.move({ 0.1f, 0.0f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            Trex.move({ -0.1f, 0.0f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            Trex.move({ 0.0f, -0.1f });
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            Trex.move({ 0.0f, 0.1f });
        }
        window.clear();
        window.draw(Ziemia);
        window.draw(Trex);
        window.display();
    }
}