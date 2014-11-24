#include "States.h"

const sf::Time timePerFrame = sf::seconds(1.f/60.f);

// MainMenu

MainMenu::MainMenu()
{
	selection = 0;

	playText.setString("Play");
	playText.setSize(35);
	playText.setPosition((GAME_WIDTH / 2) - 75, (GAME_HEIGHT / 2) - 50);

	helpText.setString("Help");
	helpText.setSize(35);
	helpText.setPosition((GAME_WIDTH / 2) - 75, (GAME_HEIGHT / 2));

	closeText.setString("Close");
	closeText.setSize(35);
	closeText.setPosition((GAME_WIDTH / 2) - 75, (GAME_HEIGHT / 2) + 50);
}

int MainMenu::Run(sf::RenderWindow &window)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					return -1;
				}
				//keyboard selection
				if (event.type == sf::Event::KeyPressed)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						if(selection > 0) {
							selection--;
						} else {
							selection = 0;
						}
						break;
					case sf::Keyboard::Down:
						if(selection < 2) {
							selection++;
						} else {
							selection = 2;
						}
						break;
					case sf::Keyboard::Return:
						//Play button
						if (selection == 0)
						{
								//Play 
								return 1;
						}
						//Help button
						else if (selection == 1)
						{
							return 2;
						}
						else
						{
							return -1;
						}
						break;
					default:
						break;
					}
				}
			}
			Update(timePerFrame);
		}
		Render(window);
	}
	return -1;
}

void MainMenu::Update(sf::Time deltaTime)
{
	//change the color depending on selection
		if (selection == 0)//Play
		{
			playText.setColor	 (sf::Color(255, 128,   0));
			helpText.setColor(sf::Color(255, 255, 255));
			closeText.setColor	 (sf::Color(255, 255, 255));
		}
		else if (selection == 1)//Help
		{
			playText.setColor	 (sf::Color(255, 255, 255));
			helpText.setColor(sf::Color(255, 128,   0));
			closeText.setColor	 (sf::Color(255, 255, 255));
		}
		else//Close button
		{
			playText.setColor	 (sf::Color(255, 255, 255));
			helpText.setColor(sf::Color(255, 255, 255));
			closeText.setColor	 (sf::Color(255, 128,   0));
		}
}

void MainMenu::Render(sf::RenderWindow &window)
{
	window.clear();
	playText.Render(window);
	helpText.Render(window);
	closeText.Render(window);
	window.display();
}

//Main Menu

