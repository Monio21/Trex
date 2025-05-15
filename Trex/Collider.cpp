#include "Collider.h"

void Collider::checkCollision(Trex &trex, sf::FloatRect rect2, bool& death, bool& start) {
	if (trex.getGlobalBounds().findIntersection(rect2).has_value()) {
		trex.setTexture(4);
		death = true;
		start = false;
	 }
}