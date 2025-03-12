#include "Utility.h"

sf::Texture BLUE;
sf::Texture GREY;
sf::Texture GREEN;
sf::Texture ORANGE;
sf::Texture PINK;
sf::Texture PURPLE;
sf::Texture RED;
sf::Texture WHITE;

sf::Font FONT;

std::random_device rd;
std::mt19937 gen(rd());

void loadFiles()
{
	if (!BLUE.loadFromFile("resources\\squares\\blue.png"))
		throw std::exception("Couldn't load blue square");

	if (!GREY.loadFromFile("resources\\squares\\grey.png"))
		throw std::exception("Couldn't load grey square");

	if (!GREEN.loadFromFile("resources\\squares\\green.png"))
		throw std::exception("Couldn't load green square");

	if (!ORANGE.loadFromFile("resources\\squares\\orange.png"))
		throw std::exception("Couldn't load orange square");

	if (!PINK.loadFromFile("resources\\squares\\pink.png"))
		throw std::exception("Couldn't load pink square");

	if (!PURPLE.loadFromFile("resources\\squares\\purple.png"))
		throw std::exception("Couldn't load purple square");

	if (!RED.loadFromFile("resources\\squares\\red.png"))
		throw std::exception("Couldn't load red square");
	
	if (!WHITE.loadFromFile("resources\\squares\\white.png"))
		throw std::exception("Couldn't load white square");

	if (!FONT.openFromFile("resources\\font.ttf"))
		throw std::exception("Couldn't load font");
}