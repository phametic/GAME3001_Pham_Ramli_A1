#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <SFML/Graphics.hpp>

#define GAME_WIDTH 800
#define GAME_HEIGHT 600

class StateManager 
{
public:
	virtual int Run(sf::RenderWindow &window) = 0;
};

#endif