#include "TTile.h"

// row and column represent the row and column of the middle square of the T tile

TTile::TTile(std::vector<std::vector<GridSquare>>& gridRef, bool& emptySpace)
	:Tile{ gridRef, {1, COLUMNS - 2} }
{
	GridSquare& sq1 = grid[row][column - 1];
	GridSquare& sq2 = grid[row][column];
	GridSquare& sq3 = grid[row][column + 1];
	GridSquare& sq4 = grid[row+1][column];

	// check if any is already occupied then return a flag that will end the game
	if (sq1.square || sq2.square || sq3.square || sq4.square)
		emptySpace = false;

	// arrange the 4 tile squares
	sq1.set_square(&squares[0]);
	sq2.set_square(&squares[1]);
	sq3.set_square(&squares[2]);
	sq4.set_square(&squares[3]);
}

bool TTile::rotate_tile()
{
	return true;
}

bool TTile::move_tile(Movement m)
{
	if (collided)
		return false;

	if (m == Down)
	{
		if (rotation == South)
		{

		}
		else if (rotation == North)
		{

		}
		else if (rotation == East)
		{

		}
		else
		{

		}
	}
	else if (m == Left)
	{
		if (rotation == South)
		{

		}
		else if (rotation == North)
		{

		}
		else if (rotation == East)
		{

		}
		else
		{

		}
	}
	else
	{
		if (rotation == South)
		{

		}
		else if (rotation == North)
		{

		}
		else if (rotation == East)
		{

		}
		else
		{

		}
	}
	return true;
}