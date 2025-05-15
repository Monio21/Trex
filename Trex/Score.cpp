#include "Score.h"

Score::Score(float scrollSpeed, sf::Text text) : distance(0.0f), scrollSpeed(scrollSpeed), score(0), text(text), highscore(0)
{};
void Score::update(float multiplier) {
	distance += scrollSpeed;
	score = int((distance / 25.0f) * multiplier);
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
int Score::getHighScore() {
	return highscore;
}
