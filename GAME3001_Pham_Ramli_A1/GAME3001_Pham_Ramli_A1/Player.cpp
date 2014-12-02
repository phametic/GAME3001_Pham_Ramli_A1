#include "Player.h"

Player::Player()
	: decel(0.8f) 
	, maxVelocity(400.f,400.f)
	, velocity(0.f,0.f)
	, Position (100.f, 300.f)
{
	playerSpeed = 100;
	health = 10;
	isActive = true;

	IsMovingUp = false;
	IsMovingDown = false;
	IsMovingLeft = false;
	IsMovingRight = false;
	IsShootingBullet = false;

	playerTexture.loadFromFile("Assets/Images/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(Position);
	playerSprite.setScale(2.0f, 2.0f);
}


void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
		if (key == sf::Keyboard::W)
		IsMovingUp = isPressed;
		else if (key == sf::Keyboard::S)
		IsMovingDown = isPressed;
		else if (key == sf::Keyboard::A)
		IsMovingLeft = isPressed;
		else if (key == sf::Keyboard::D)
		IsMovingRight = isPressed;
		else if (key == sf::Keyboard::Space)
		IsShootingBullet = isPressed;
}

void Player::Update(sf::Time elapsedTime)
{
	if (IsMovingUp) {
				if(playerSprite.getPosition().y < 10)
					velocity.y = 0;
				else
				velocity.y -= playerSpeed;
			} else { 
				velocity.y *= decel; 
			}
	if (IsMovingDown) {
				if(playerSprite.getPosition().y > GAME_HEIGHT - 100)
					velocity.y = 0;
				else
				velocity.y += playerSpeed;
			} else { 
				velocity.y *= decel; 
			}

	if (IsMovingLeft) {
				if(playerSprite.getPosition().x < 10) {
					velocity.x = 0;
				} else {
				velocity.x -= playerSpeed;
				}
			}  else {
				velocity.x *= decel;
			}
		if (IsMovingRight) {
				if(playerSprite.getPosition().x> GAME_WIDTH - 70)
					velocity.x = 0;
				else
				velocity.x += playerSpeed;
			} else {
				velocity.x *= decel;
			}

			float actualSpeed = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));

			if(actualSpeed > maxVelocity.x)
				velocity.x *= maxVelocity.x / actualSpeed;

				if(actualSpeed > maxVelocity.y)
				velocity.y *= maxVelocity.y / actualSpeed;


			playerSprite.move(velocity * elapsedTime.asSeconds());
}

void Player::Render(sf::RenderWindow &window)
{
	if(isActive)
	window.draw(playerSprite);
}

sf::Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}