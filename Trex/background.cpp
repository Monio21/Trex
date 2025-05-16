#include "background.h"

background::background(sf::Texture texture)
	: texture(texture), rect(sf::Vector2f(1440.0f, 413.0f)), movementSpeed(-4.0f)
{
	rect.setTexture(&this->texture);
};
void background::setPosition(float x, float y)
{
	rect.setPosition({ x, y });
}
sf::Vector2f background::getPosition()
{
	return rect.getPosition();
}
void background::move(float multiplier)
{
	rect.move({ movementSpeed * multiplier, 0 });
}
void background::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}


