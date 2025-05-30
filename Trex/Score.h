#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

class Score
{
public:
	Score(sf::Text text);
	~Score() = default;

	void update(float multiplier, sf::Sound &sound);
	void draw(sf::RenderWindow& window);
	void reset();
	int getScore();
	int getHighScore();
	void setHighscore();
private:
	sf::Text text;
	float distance;
	float scrollSpeed;
	int score;
	int highscore;
};

