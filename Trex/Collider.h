#pragma once
#include <SFML/Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	bool CheckCollision(Collider& other, float push);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();
private:
	sf::RectangleShape& body;
};

