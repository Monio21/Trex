#pragma once
#include <SFML/Graphics.hpp>
class Score
{
public:
	Score(float scrollSpeed, sf::Text text);
	void update(float multiplier);
	void draw(sf::RenderWindow& window);
	void reset();
	int getScore();
private:
	sf::Text text;
	float distance;
	float scrollSpeed;
	int score;
	int highscore;
};

