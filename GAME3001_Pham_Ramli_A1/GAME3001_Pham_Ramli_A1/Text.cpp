#include "Text.h"

//Text
Text::Text(int size)
{
	font.loadFromFile("Assets/Fonts/kenvector_future.ttf");
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(size);
}

Text::Text(std::string output, int size)
{
	font.loadFromFile("Assets/Fonts/kenvector_future.ttf");
	text.setFont(font);
	text.setString(output);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(size);
}

Text::Text()
{
	font.loadFromFile("Assets/Fonts/kenvector_future.ttf");
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
}

void Text::setString(std::string string)
{
	text.setString(string);
}

void Text::setSize(int size)
{
	text.setCharacterSize(size);
}

void Text::setColor(sf::Color color)
{
	text.setColor(color);
}

void Text::setPosition(float x, float y)
{
	text.setPosition(x, y);
}

void Text::setOrigin(float x, float y)
{
	text.setOrigin(x, y);
}

void Text::Update(std::stringstream &stream, int value)
{
	text.setString(stream.str());
	stream.str("");
	stream << value;
}

void Text::Render(sf::RenderWindow &window)
{
	window.draw(text);
}

sf::FloatRect Text::getGlobalBounds()
{
	return text.getGlobalBounds();
}
