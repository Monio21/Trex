#include "Trex.h"

Trex::Trex(sf::Sprite sprite, sf::Texture& Idle)
	: Character(sprite),
	rect({ {0,0}, {24,16} }), frameWidth(24), velocityY(0.0f), gravity(300.0f), jumpHeight(330.0f),
	isJumping(false), groundYpos(300.0f)
{
	texture_idle = Idle;
	texture_run.loadFromFile("olaf/base/move.png");
	texture_jump.loadFromFile("olaf/base/jump.png");
	texture_death.loadFromFile("olaf/base/dead.png");

};
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
void Trex::jump(sf::Sound &sound)
{
	if (!isJumping) {
		velocityY = -jumpHeight;
		isJumping = true;
		sound.play();
		setTexture(3);
	}
}
void Trex::applyGravity() {
	velocityY += gravity * 0.03f;
	sprite.move({ 0.0f, velocityY * 0.03f });
	if (sprite.getPosition().y >= groundYpos) {
		sprite.setPosition({ sprite.getPosition().x, groundYpos });
		velocityY = 0.0f;
		isJumping = false;
		setTexture(2);
	}
}