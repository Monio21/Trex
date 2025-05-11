#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class Collider
{
public:
	static bool checkCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};