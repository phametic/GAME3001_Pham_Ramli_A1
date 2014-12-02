#include "SpawnManager.h"

SpawnManager::SpawnManager() 
{
	
}

void SpawnManager::createBullets(sf::Time &bulletTimer, sf::Time &previousShotTimer, std::vector<Bullet> &vector, Player &player) 
{
	if(previousShotTimer >= bulletTimer)
	{
		Bullet bullet;
		bullet.SetPosition(player.getPosition().x + 30, player.getPosition().y - 15);
		vector.push_back(bullet);
		previousShotTimer = sf::Time::Zero;
	}
}