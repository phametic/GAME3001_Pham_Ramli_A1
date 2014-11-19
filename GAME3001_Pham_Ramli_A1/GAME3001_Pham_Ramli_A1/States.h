#ifndef STATES_H
#define STATES_H

#include "StateManager.h"
#include "Text.h"

class MainMenu : public StateManager
{
public:
	MainMenu();
	virtual int Run(sf::RenderWindow &window);
	void Update(sf::Time deltaTime);
	void Render(sf::RenderWindow &window);
	void processEvents(sf::RenderWindow &window);


private:
	sf::Event event;
	int selection;
	Text playText, helpText, closeText;

};

#endif