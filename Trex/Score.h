#pragma once
#include <SFML/Graphics.hpp>

class Score
{
public:
	Score(sf::Text text);
	~Score() = default;

	void update(float multiplier);
	void draw(sf::RenderWindow& window);
	void reset();
	int getScore();
	int getHighScore();
private:
	sf::Text text;
	float distance;
	float scrollSpeed;
	int score;
	int highscore;
};

