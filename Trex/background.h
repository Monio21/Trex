#pragma once
#include <SFML/Graphics.hpp>
class background 
{
public:
	background(sf::Texture texture);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void setTexture();
	void move(float x, float y);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape rect;
	sf::Texture texture;

};

