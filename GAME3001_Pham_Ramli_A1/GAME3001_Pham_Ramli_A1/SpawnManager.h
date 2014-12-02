#ifndef SPAWNMANAGER_H
#define SPAWNMANAGER_H

#include "Player.h"
#include "Bullet.h"

class SpawnManager 
{
public:
	SpawnManager();
	void createBullets(sf::Time &bulletTimer, sf::Time &previousShotTimer, std::vector<Bullet> &vector, Player &player);

private:

};

#endif