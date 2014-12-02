#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

#include "Enemy1.h"
#include "Bullet.h"
#include "Collision.h"

class UpdateManager {
	public:
		void EnemyMinionUpdate(std::vector<Enemy1> &vector, std::vector<Enemy1>::iterator &iterator, sf::Time elapsedTime);
		void PlayerBulletUpdate(std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator, std::vector<Enemy1> &enemy, int &points, sf::Time elapsedTime);
};

#endif