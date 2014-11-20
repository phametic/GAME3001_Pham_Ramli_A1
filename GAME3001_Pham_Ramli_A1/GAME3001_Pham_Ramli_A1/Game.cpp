#include "Game.h"

const sf::Time timePerFrame = sf::seconds(1.f/60.f);

Game::Game()
{

}

int Game::Run(sf::RenderWindow &window) 
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	srand( time(0));
	while (window.isOpen()) 
	{

		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(window);
			Update(timePerFrame);

		}
		Render(window);
	}
	return -1;
}

void Game::processEvents(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			//player.handlePlayerInput(event.key.code, true);
			break;
			case sf::Event::KeyReleased:
			//player.handlePlayerInput(event.key.code, false);
			break;
			case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Game::Update(sf::Time deltaTime)
{

}

void Game::Render(sf::RenderWindow &window)
{
	window.clear();

	window.display();
}

