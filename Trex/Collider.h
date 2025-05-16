#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Trex.h"
#include <SFML/Audio.hpp>

class Collider
{
public:
	static void checkCollision(Trex &trex, sf::FloatRect rect2, bool &death, bool &start, sf::Sound &death_sound);
};