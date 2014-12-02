#include "UpdateManager.h"

void UpdateManager::EnemyMinionUpdate(std::vector<Enemy1> &vector, std::vector<Enemy1>::iterator &iterator, sf::Time elapsedTime)
{
	for(iterator = vector.begin(); iterator != vector.end();) {
		if(iterator->isActive()) {
			iterator->update(elapsedTime);
			++iterator;
		} else {
			iterator = vector.erase(iterator);
		}
	}
}

void UpdateManager::PlayerBulletUpdate(std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator, std::vector<Enemy1> &enemy, int &points, sf::Time elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if(iterator->isActive())
		{
			collision::PlayerBulletToEnemyCollision(iterator, enemy, points);
			iterator->update(elapsedTime);
			++iterator;
		} else {
			iterator = vector.erase(iterator);
		}
	}
}