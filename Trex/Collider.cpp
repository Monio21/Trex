#include "Collider.h"

void Collider::checkCollision(Trex &trex, sf::FloatRect rect2, bool& death, bool& start, sf::Sound &death_sound) {
	if (trex.getGlobalBounds().findIntersection(rect2).has_value()) {
		trex.setTexture(4);
		death_sound.play();
		death = true;
		start = false;
	 }
}