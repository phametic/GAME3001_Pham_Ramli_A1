#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "Player.h"

class Game : public StateManager
{
public:
	Game();
	virtual int Run(sf::RenderWindow &window);
	void Update(sf::Time deltaTime);
	void Render(sf::RenderWindow &window);
	void processEvents(sf::RenderWindow &window);

private:
	Player player;
};

#endif