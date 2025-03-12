#include "Game.h"

#include "SquareTile.h"
#include "BarTile.h"
#include "TTile.h"

#include "Utility.h"

Game::Game():
	window{ VideoMode({(int)WIDTH, (int)HEIGHT}), "Tetris"},
	grid{(int) ROWS},
	gridBorder{{COLUMNS * SQUARE_SIDE, ROWS * SQUARE_SIDE}}
{
	window.setFramerateLimit(60);

	// grid Initialization
	for (int i = 0; i < ROWS; i++)
	{
		grid[i].resize(COLUMNS);
	}

		// grid positions
	float rowOffset = GRID_Y;
	for (int i = 0; i < ROWS; i++)
	{
		float columnOffset = GRID_X;
		for (int j = 0; j < COLUMNS; j++)
		{
			grid[i][j].x = columnOffset;
			grid[i][j].y = rowOffset;
			columnOffset += SQUARE_SIDE;
		}
		rowOffset += SQUARE_SIDE;
	}

		// grid border
	gridBorder.setPosition({ GRID_X, GRID_Y });
	gridBorder.setFillColor(sf::Color::Transparent);
	gridBorder.setOutlineThickness(2.f);

	// first tile
	tile = newTile().second;
}

void Game::draw()
{
	// grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (grid[i][j].square)
			{
				window.draw(*(grid[i][j].square));
			}
		}
	}
	window.draw(gridBorder);
}

void Game::play()
{

	while (window.isOpen())
	{
		static sf::Time sleepTime = sf::milliseconds(400);
		sf::Clock clock;

		while (clock.getElapsedTime() < sleepTime)
		{
			if (tile->collided)
				break;

			while (const std::optional event = window.pollEvent())
			{
				if (event->is<Event::Closed>())
				{
					window.close();
				}
				else if (auto* e = event->getIf<Event::KeyPressed>())
				{
					handle_input(e->code);
				}

				if (clock.getElapsedTime() > sleepTime)
				{
					break;
				}
			}
		}

		if (tile->collided)
		{
			// end game
			if (tile->row == 0)
				return;

			std::pair<bool, Tile*> temp = newTile();
			tile = temp.second;

			window.clear();
			draw();
			window.display();

			// end game
			if (!temp.first)
				return;

			continue;
		}


		tile->move_tile(Tile::Down);

		window.clear();
		draw();
		window.display();
	}
}


void Game::handle_input(const sf::Keyboard::Key& k)
{
		if (k == sf::Keyboard::Key::Down)
		{
			if (!tile->move_tile(Tile::Down))
				return;
		}
		else if (k == sf::Keyboard::Key::Up)
		{
			if (!tile->rotate_tile())
				return;
		}
		else if (k == sf::Keyboard::Key::Left)
		{
			if (!tile->move_tile(Tile::Left))
				return;
		}
		else if (k == sf::Keyboard::Key::Right)
		{
			if (!tile->move_tile(Tile::Right))
				return;
		}
		else
		{
			return;
		}

		window.clear();
		draw();
		window.display();
}

std::pair<bool, Tile*> Game::newTile()
{
	static enum Tiles{Square, Bar, T};
	static std::uniform_int_distribution<unsigned short> tilesDist(0, 1);

	Tile* ptr;

	bool emptySpace = true;

	switch ((Tiles) tilesDist(gen))
	{
	case Square:
		ptr = new SquareTile(grid, emptySpace);
		break;
	case Bar:
		ptr = new BarTile(grid, emptySpace);
		break;
	case T:
		ptr = new TTile(grid, emptySpace);
		break;
	}

	oldTiles.push_back(ptr);
	return { emptySpace, ptr };
}

Game::~Game()
{
	for (auto x : oldTiles)
		delete x;
}
