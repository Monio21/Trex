#include "background.h"

background::background(sf::Texture texture)
	: texture(texture), rect(sf::Vector2f(1440.0f, 413.0f))
{};
void background::setPosition(float x, float y)
{
	rect.setPosition({ x, y });
}
sf::Vector2f background::getPosition()
{
	return rect.getPosition();
}
void background::setTexture()
{
	rect.setTexture(&texture);
}
void background::move(float x, float y)
{
	rect.move({ x, y });
}
void background::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}
void background::setRect(float x, float y)
{
	rect.setSize({ x, y });
}
void background::setScale(float x, float y)
{
	rect.setScale({ x, y });
}


