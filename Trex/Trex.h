#pragma once
#include <SFML/Graphics.hpp>

class Trex
{
public:
	Trex(sf::Sprite sprite, sf::Texture texture_idle, sf::Texture texture_run, sf::Texture texture_jump, sf::Texture texture_death);
	void setPosition(float x, float y);
	void setScale(float x, float y);
	void setOrigin();
	void setTexture(int phase);
	void setTextureRect();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void jump();
	void applyGravity();
	sf::FloatRect getGlobalBounds();

private:
	sf::Sprite sprite;
	sf::Texture texture_idle;
	sf::Texture texture_run;
	sf::Texture texture_jump;
	sf::Texture texture_death;
	sf::IntRect rect;
	sf::RenderWindow window;
	int frameWidth;
	float timer;
	float switchTime;
	float velocityY;
	float gravity;
	float jumpHeight;
	bool isJumping;
	float groundYpos;
};

