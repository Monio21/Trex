#include "Score.h"

Score::Score(float scrollSpeed,sf::Text text) : distance(0.0f), scrollSpeed(scrollSpeed), score(0), text(text) 
{};
void Score::update() {
	distance += scrollSpeed;
	score = int(distance / 50.0f);
	text.setString("Score: " + std::to_string(score));
}
void Score::draw(sf::RenderWindow& window) {
	window.draw(text);
}
void Score::reset() {
	if (score > highscore) {
		highscore = score;
	}
	distance = 0.0f;
	score = 0;
}
int Score::getScore() {
	return score;
}
