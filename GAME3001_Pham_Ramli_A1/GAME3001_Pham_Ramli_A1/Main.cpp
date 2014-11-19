#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "States.h"

int main()
{
   std::vector<StateManager*> states;
   int screenState = 0;

   sf::RenderWindow window;
   window.create(sf::VideoMode(GAME_WIDTH,GAME_HEIGHT), "GAME3001_Pham_Ramli_A1", sf::Style::Close);
   
   MainMenu state0;
   states.push_back(&state0);

   while (screenState >= 0)
	{
		//main loop
		screenState = states[screenState]->Run(window);
	}

   return 0;
}