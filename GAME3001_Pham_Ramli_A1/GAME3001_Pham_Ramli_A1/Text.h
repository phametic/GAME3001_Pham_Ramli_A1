#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Text
{
public:
	Text(int size);
	Text(std::string output, int size);
	Text();
	void setString(std::string string);
	void setSize(int size);
	void setColor(sf::Color color);
	void setPosition(float x, float y);
	void setOrigin(float x, float y);
	void Update(std::stringstream &stream, int value);
	void Render(sf::RenderWindow &window);
	sf::FloatRect getGlobalBounds();
private:
	sf::Text text;
	sf::Font font;
};


#endif