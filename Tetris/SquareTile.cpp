#include "SquareTile.h"

SquareTile::SquareTile(std::vector<std::vector<GridSquare>>& gridRef, bool& emptySpace)
	:Tile{ gridRef , {0, COLUMNS - 2} }
{
	// refrences to the space that's supposed to be occupied by the squaretile
	GridSquare& tL = gridRef[row][column];
	GridSquare& tR = gridRef[row][column + 1];
	GridSquare& bL = gridRef[row + 1][column];
	GridSquare& bR = gridRef[row + 1][column + 1];

	// check if any is already occupied then return a flag that will end the game
	if (tL.square || tR.square || bL.square || bR.square)
		emptySpace = false;

	// arrange the 4 tile squares
	tL.set_square(&squares[0]);
	tR.set_square(&squares[1]);
	bL.set_square(&squares[2]);
	bR.set_square(&squares[3]);
}

bool SquareTile::rotate_tile()
{
	return false;
}

bool SquareTile::move_tile(Movement m)
{
	if (collided)
		return false;

	if (m == Down)
	{
		static int BOTTOM = ROWS - 2;
		if (row == BOTTOM || grid[row + 2][column].square || grid[row + 2][column + 1].square)
		{
			collided = true;
			return false;
		}

		grid[row + 2][column].set_square(grid[row][column].square);
		grid[row + 2][column+1].set_square(grid[row][column+1].square);

		grid[row][column].square = nullptr;
		grid[row][column + 1].square = nullptr;

		row++;
	}
	else if (m == Left)
	{
		if (column == 0 || grid[row][column-1].square || grid[row+1][column-1].square)
			return false;

		grid[row][column-1].set_square(grid[row][column+1].square);
		grid[row + 1][column - 1].set_square(grid[row+1][column + 1].square);

		grid[row][column + 1].square = nullptr;
		grid[row + 1][column + 1].square = nullptr;

		column--;
	}
	else
	{
		static int RIGHT_BORDER = COLUMNS - 2;

		if (column == RIGHT_BORDER || grid[row][column + 2].square || grid[row + 1][column + 2].square)
			return false;

		grid[row][column +2].set_square(grid[row][column].square);
		grid[row + 1][column + 2].set_square(grid[row + 1][column].square);

		grid[row][column].square = nullptr;
		grid[row + 1][column].square = nullptr;

		column++;
	}

	return true;
}