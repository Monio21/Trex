#include "background.h"

background::background(sf::Texture texture)
	: texture(texture), rect(sf::Vector2f(1440.0f, 413.0f)), movementSpeed(-4.0f)
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
void background::move(float multiplier)
{
	rect.move({ movementSpeed * multiplier, 0 });
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
sf::FloatRect background::getGlobalBounds()
{
	return rect.getGlobalBounds();
}
void background::moveAndReset(float multiplier) {
	rect.move({ movementSpeed * multiplier, 0 });

	static std::mt19937 generate(static_cast<unsigned int>(std::time(nullptr)));
	int min = static_cast<int>(500 + (multiplier - 1.0f) * 150);
	int max = min + 300;
	static std::uniform_int_distribution<int> distance(min, max);

	if (rect.getPosition().x < -20.0f) {
		float x = 900  + (static_cast<float>(distance(generate)) * multiplier);
		rect.setPosition({ x, 325.0f });
	}
}


