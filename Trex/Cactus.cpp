#include "Cactus.h"


Cactus::Cactus(sf::Texture texture)
	: background(texture)
{
	rect.setSize({ 230.0f, 295.0f });
	rect.setScale({ 0.20f, 0.20f });
};
sf::FloatRect Cactus::getGlobalBounds()
{
	return rect.getGlobalBounds();
}
void Cactus::moveAndReset(float multiplier) {
	rect.move({ movementSpeed * multiplier, 0 });

	static std::mt19937 generate(static_cast<unsigned int>(std::time(nullptr)));
	int min = static_cast<int>(700 + (multiplier - 1.0f) * 150);
	int max = min + 300;
	std::uniform_int_distribution<int> distance(min, max);

	if (rect.getPosition().x < -20.0f) {
		float x = 900 + (static_cast<float>(distance(generate)) * multiplier);
		rect.setPosition({ x, 325.0f });
	}
}
