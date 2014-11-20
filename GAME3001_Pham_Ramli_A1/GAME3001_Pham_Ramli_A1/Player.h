#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
public:
		Player();
		virtual void Update(sf::Time elapsedTime);
		virtual void Render(sf::RenderWindow &window);
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::Vector2f Position;
};

#endif