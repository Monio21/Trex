#include "Trex.h"

Trex::Trex(sf::Sprite sprite, sf::Texture texture_idle, sf::Texture texture_run, sf::Texture texture_jump, sf::Texture texture_death)
	: sprite(sprite), texture_idle(texture_idle), texture_run(texture_run), texture_jump(texture_jump), texture_death(texture_death),
	rect({ {0,0}, {24,24} }), frameWidth(24), timer(0.0f), switchTime(15.0f)
{};
void Trex::setPosition(float x, float y)
{
	sprite.setPosition({ x, y });
}
void Trex::setScale(float x, float y)
{
	sprite.setScale({ x, y });
}
void Trex::setOrigin()
{
	sprite.setOrigin({ sprite.getTextureRect().size.x / 2.0f, sprite.getTextureRect().size.y / 2.0f });
}
void Trex::setTexture(int phase)
{
	if (phase == 1) {
		sprite.setTexture(texture_idle);
	}
	if (phase == 2) {
		sprite.setTexture(texture_run);
	}
	if (phase == 3) {
		sprite.setTexture(texture_jump);
	}
	if (phase == 4) {
		sprite.setTexture(texture_death);
	}
}
void Trex::setTextureRect()
{
	sprite.setTextureRect(rect);
}
void Trex::move(float x, float y)
{
	sprite.move({ x, y });
}
void Trex::update(float deltaTime)
{
	
	timer += deltaTime;
	if (timer >= switchTime) {
		frameWidth += 24;
		if (frameWidth >= sprite.getTexture().getSize().x)
			frameWidth = 0;
		if (frameWidth < sprite.getTexture().getSize().x)
			sprite.setTextureRect({ {frameWidth , 0 }, {24, 24} });
		timer = 0.0f;
	}
}
void Trex::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}