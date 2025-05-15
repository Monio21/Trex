#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>

class background 
{
public:
	background(sf::Texture texture);
	~background() = default;

	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void setTexture();
	void move(float multiplier);
	void draw(sf::RenderWindow& window);
	void setRect(float x, float y);
	void setScale(float x, float y);
	sf::FloatRect getGlobalBounds();
	void moveAndReset(float multiplier);

private:
	sf::RectangleShape rect;
	sf::Texture texture;
	float movementSpeed;
};

