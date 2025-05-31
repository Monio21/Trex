#include "Character.h"

Character::Character(sf::Sprite sprite)
	: sprite(sprite),timer(0.0f), switchTime(0.1f)
{};
void Character::setPosition(float x, float y)
{
	sprite.setPosition({ x, y });
}
void Character::setScale(float x, float y)
{
	sprite.setScale({ x, y });
}
void Character::setOrigin()
{
	sprite.setOrigin({ sprite.getTextureRect().size.x / 2.0f, sprite.getTextureRect().size.y / 2.0f });
}
void Character::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
sf::FloatRect Character::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}