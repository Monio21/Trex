#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Trex.h"

class Collider
{
public:
	static void checkCollision(Trex &trex, sf::FloatRect rect2, bool &death, bool &start);
};