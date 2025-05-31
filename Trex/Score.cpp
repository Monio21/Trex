#include "Score.h"

Score::Score(sf::Text text) : distance(0.0f), scrollSpeed(4.0f), score(0), text(text), highscore(0)
{};
void Score::update(float multiplier, sf::Sound &sound) {
	distance += scrollSpeed;
	score = int((distance / 25.0f) * multiplier);
	if (score % 300 == 0 && score != 0) {
		sound.play();
	}
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
void Score::setHighscore() {
	std::filesystem::path path = "logs/highscores.txt";
	std::ifstream file(path);
	std::vector<int> localHighScores;
	std::string line;
	std::regex reg(R"(HighScore:\s*(\d+))");
	std::smatch match;
	int var;
	
	if (file) {
		std::getline(file, line);
		std::getline(file, line);
		
		while (std::getline(file, line)) {
			if (std::regex_search(line, match, reg)) {
				var = std::stoi(match[1]);
				localHighScores.push_back(var);
			}
		}
		file.close();
	}
	highscore = *std::max_element(localHighScores.begin(), localHighScores.end());
}
