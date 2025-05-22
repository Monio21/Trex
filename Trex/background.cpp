#include "Background.h"

Background::Background(sf::Texture texture)
	: texture(texture), rect(sf::Vector2f(1440.0f, 413.0f)), movementSpeed(-4.0f)
{
	rect.setTexture(&this->texture);
};
void Background::setPosition(float x, float y)
{
	rect.setPosition({ x, y });
}
sf::Vector2f Background::getPosition()
{
	return rect.getPosition();
}
void Background::move(float multiplier)
{
	rect.move({ movementSpeed * multiplier, 0 });
}
void Background::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}


