#ifndef ENEMY1_H
#define ENEMY1_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Enemy1  {

	public:
		Enemy1(sf::Vector2f);
		~Enemy1();
		 void update(sf::Time elapsedTime);
		 void render(sf::RenderWindow &window);
		sf::Texture *Texture;
		sf::Sprite *Sprite;
		sf::Vector2f enemyPosition;
		sf::Vector2f maxVelocity;
		sf::Vector2f velocity;
		float enemyMoveSpeed;
		int getDamage();
		void OnHit(int damage);
		void setActive(bool active) {
			Active = active;
		}

		bool isActive() {
			return Active;
		}
				int getHealth()
		{
			return Health;
		}

		void reduceHealth(int Damage)
		{
			int newHealth = Health - Damage;
			Health = newHealth;
		}

		void setHealth(int health)
		{
			Health = health;
		}
		int getDamage() {
			return Damage;
		}
	private:
		bool Active;
		int Health;
		int Damage;
};

#endif