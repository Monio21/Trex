#pragma once
#include <SFML/Graphics.hpp>
#include "background.h"
class Cactus : public background
{
public:
	Cactus(sf::Texture texture);
	~Cactus() = default;

	sf::FloatRect getGlobalBounds();
	void move(float multiplier) override;
};

