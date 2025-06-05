#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"

class Trex : public Character
{
public:
	Trex(sf::Sprite sprite, sf::Texture& Idle);
	~Trex() = default;

	void setTexture(int phase) override;
	void setTextureRect() override;
	void update(float deltaTime) override;
	void jump(sf::Sound &sound);
	void applyGravity();

private:
	sf::Texture texture_idle;
	sf::Texture texture_run;
	sf::Texture texture_jump;
	sf::Texture texture_death;
	sf::IntRect rect;
	int frameWidth;
	float velocityY;
	float gravity;
	float jumpHeight;
	bool isJumping;
	float groundYpos;
};

