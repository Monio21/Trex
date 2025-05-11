#include "Collider.h"

bool Collider::checkCollision(sf::FloatRect rect1, sf::FloatRect rect2) {
	return rect1.findIntersection(rect2).has_value();
}