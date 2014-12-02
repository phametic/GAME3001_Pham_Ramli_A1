#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "Bullet.h"

class RenderManager
{
public:
	void PlayerBulletRender(sf::RenderWindow &window, std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator);
};

#endif