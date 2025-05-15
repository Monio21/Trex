#pragma once
#include <SFML/Graphics.hpp>
class Character
{
public:
	Character(sf::Sprite sprite);
	virtual ~Character() = default;

	virtual void setPosition(float x, float y);
	virtual void setScale(float x, float y);
	virtual void setOrigin();
	virtual void setTexture(int phase) = 0;
	virtual void setTextureRect() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window);
	virtual sf::FloatRect getGlobalBounds();

protected:
	sf::Sprite sprite;
	float timer;
	float switchTime;
};

