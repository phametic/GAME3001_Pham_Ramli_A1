#ifndef PLAYER_H
#define PLAYER_H

#include "StateManager.h"
#include <iostream>
#include <vector>

class Player
{
public:
		Player();
		virtual void Update(sf::Time elapsedTime);
		virtual void Render(sf::RenderWindow &window);
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

		sf::Vector2f getPosition();

		sf::Sprite playerSprite;

		bool isActive;
private:

	bool IsMovingUp;
	bool IsMovingDown;
	bool IsMovingLeft;
	bool IsMovingRight;
	bool IsShootingBullet;

	int health;
	float playerSpeed;
	float decel;

	sf::Vector2f maxVelocity;
	sf::Vector2f velocity;

	sf::Vector2f Position;

	sf::Texture playerTexture;

};

#endif