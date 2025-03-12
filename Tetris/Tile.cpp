#include "Tile.h"
#include "Utility.h"

Tile::Tile(std::vector<std::vector<GridSquare>>& gridRef, const std::pair<int, int>& columnBounds)
	: grid{ gridRef },
	row{ 0 },
	rotation{South},
	squares{SPT, RectangleShape({SQUARE_SIDE, SQUARE_SIDE})},
	collided{false}
{
	static std::uniform_int_distribution<unsigned short> colorDist(0, 7);

	std::uniform_int_distribution<unsigned short> columnDist(columnBounds.first, columnBounds.second);

	column = columnDist(gen);

	static enum Color { Blue, Grey, Green, Orange, Pink, Purple, Red, White };

	Color color = (Color) colorDist(gen);

	// color of the tile
	sf::Texture* texture;

	if (color == Blue)
	{
		texture = &BLUE;
	}
	else if (color == Grey)
	{
		texture = &GREY;
	}
	else if (color == Green)
	{
		texture = &GREEN;
	}
	else if (color == Orange)
	{
		texture = &ORANGE;
	}
	else if (color == Pink)
	{
		texture = &PINK;
	}
	else if (color == Purple)
	{
		texture = &PURPLE;
	}
	else if (color == Red)
	{
		texture = &RED;
	}
	else
	{
		texture = &WHITE;
	}

	for (int i = 0; i < SPT; i++)
	{
		squares[i].setTexture(texture);
	}
}