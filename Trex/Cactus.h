#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
class Cactus : public Background
{
public:
	Cactus(sf::Texture texture);
	~Cactus() = default;

	sf::FloatRect getGlobalBounds();
	void move(float multiplier) override;
};

