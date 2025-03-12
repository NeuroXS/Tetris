#pragma once
#include "CONSTANTS.h"
#include "GridSquare.h"
#include "Tile.h"

class Game
{
public:
	Game();
	void play();

	~Game();

private:
	void draw();
	void handle_input(const sf::Keyboard::Key& k);
	std::pair<bool, Tile*> newTile();

	sf::RenderWindow window;

	std::vector<std::vector<GridSquare>> grid;


	RectangleShape gridBorder;

	
	Tile* tile;

	// list of tiles that gonna be deleted later
	std::list<Tile*> oldTiles;
};

