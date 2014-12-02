#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"

namespace collision
{
	//Player collision against enemies
	template <class Object, class ObjectList>
	void PlayerToEnemyCollision(std::vector<ObjectList> &objList, Object &player) 
	{
		sf::Sprite *playerSprite = player.Sprite;
		for(int i = 0; i < objList.size(); i++ )
		{
			if(objList[i].isActive())
			{
				if(objList[i].Sprite->getGlobalBounds().intersects(playerSprite->getGlobalBounds()))
				{
					objList[i].setActive(false);
					player.OnHit(objList[i].getDamage());
					//player.reduceHealth(objList[i].getDamage());
				}
			}
		}
	}

	//Player bullet collision against enemies
	template <class Object, class ObjectList>
	void PlayerBulletToEnemyCollision(Object &obj, std::vector<ObjectList> &objList, int &points)
	{
		for (int i = 0; i < objList.size(); i++)
		{
			if(objList[i].isActive())
			{
				if(obj->Sprite->getGlobalBounds().intersects(objList[i].Sprite->getGlobalBounds()))
				{
					
					obj[i].setActive(false);
					points += 50;
					objList[i].OnHit(obj[i].getDamage());
					//objList[i].setActive(false);
					cout << "Bullet not active." << endl;
				}
			}
		}
	}
}

#endif