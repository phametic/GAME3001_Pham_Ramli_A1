#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"

class Bullet 
{
	public:
		Bullet();
		~Bullet();
		void update(sf::Time elapsedTime);
		void render(sf::RenderWindow &window);
		void SetPosition(float x, float y);
		sf::Sprite *Sprite;
		
		float bulletSpeed;
		sf::Vector2f bulletPosition;
		sf::Vector2f maxVelocity;
		sf::Vector2f velocity;

		int getDamage();

		void setActive(bool active) {
			Active = active;
		}

		bool isActive() {
			return Active;
		}

		
	private:
		sf::Texture *Texture;
		bool Active;
};

#endif