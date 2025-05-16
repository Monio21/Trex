#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>

class background 
{
public:
	background(sf::Texture texture);
	virtual ~background() = default;

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition();
	virtual void move(float multiplier);
	virtual void draw(sf::RenderWindow& window);
	

protected:
	sf::RectangleShape rect;
	sf::Texture texture;
	float movementSpeed;
};

