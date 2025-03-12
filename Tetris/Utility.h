#pragma once
#include <SFML/Graphics.hpp>
#include <random>
using namespace sf;


void loadFiles();

// Textures
extern sf::Texture BLUE;
extern sf::Texture GREY;
extern sf::Texture GREEN;
extern sf::Texture ORANGE;
extern sf::Texture PINK;
extern sf::Texture PURPLE;
extern sf::Texture RED;
extern sf::Texture WHITE;

extern sf::Font FONT;

// generators
extern std::random_device rd;
extern std::mt19937 gen;