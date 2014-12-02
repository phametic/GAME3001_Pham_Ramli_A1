#include "RenderManager.h"

void ::RenderManager::PlayerBulletRender(sf::RenderWindow &window, std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator)
{
	for(iterator  = vector.begin(); iterator != vector.end(); ++iterator)
		iterator->render(window);
}