#include "BarTile.h"

// bar is initially horizontal, and its lead square is the most left
// Bar rotation is only east or South

BarTile::BarTile(std::vector<std::vector<GridSquare>>& gridRef, bool& emptySpace)
	:Tile(gridRef, {0, COLUMNS - 4})
{
	GridSquare& sq1 = gridRef[row][column];
	GridSquare& sq2 = gridRef[row][column+1];
	GridSquare& sq3 = gridRef[row][column+2];
	GridSquare& sq4 = gridRef[row][column+3];

	// check if any is already occupied then return a flag that will end the game
	if (sq1.square || sq2.square || sq3.square || sq4.square)
		emptySpace = false;

	// arrange the 4 tile squares
	sq1.set_square(&squares[0]);
	sq2.set_square(&squares[1]);
	sq3.set_square(&squares[2]);
	sq4.set_square(&squares[3]);

	rotation = East;
}

bool BarTile::rotate_tile()
{
	if (rotation == East)
	{
		static int BOTTOM = ROWS - 4;
		if (row > BOTTOM)
			return false;

		for (int i = 1; i < 4; i++)
		{
			if (grid[row + i][column].square)
				return false;
		}

		for (int i = 0; i < 4; i++)
		{
			grid[row][column + i].square = nullptr;
			grid[row + i][column].set_square(&squares[i]);
		}

		rotation = South;
	}
	else
	{
		static int LEFT_BORDER = COLUMNS - 4;
		if (column > LEFT_BORDER)
			return false;

		for (int i = 1; i < 4; i++)
		{
			if (grid[row][column + i].square)
				return false;
		}

		for (int i = 0; i < 4; i++)
		{
			grid[row + i][column].square = nullptr;
			grid[row][column + i].set_square(&squares[i]);
		}

		rotation = East;
	}
	return true;
}


bool BarTile::move_tile(Movement m)
{
	if (collided)
		return false;

	if (rotation == East)
	{
		if (m == Down)
		{
			int nextRow = row + 1;
			if (nextRow == ROWS)
			{
				collided = true;
				return false;
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (grid[nextRow][column + i].square)
					{
						collided = true;
						return false;
					}
				}
			}

			for (int i = 0; i < 4; i++)
			{
				grid[row][column + i].square = nullptr;
				grid[nextRow][column + i].set_square(&squares[i]);
			}

			row++;
		}
		else if (m == Left)
		{
			if (column == 0 || grid[row][column-1].square)
			{
				return false;
			}

			grid[row][column - 1].set_square(grid[row][column + 3].square);

			grid[row][column + 3].square = nullptr;

			column--;
		}
		else
		{
			static int RIGHT_BORDER = COLUMNS - 4;
			if (column == RIGHT_BORDER || grid[row][column+4].square)
			{
				return false;
			}

			grid[row][column + 4].set_square(grid[row][column].square);

			grid[row][column].square = nullptr;

			column++;
		}
	}
	else
	{
		if (m == Down)
		{
			if (row + 4 == ROWS || grid[row + 4][column].square)
			{
				collided = true;
				return false;
			}

			grid[row + 4][column].set_square(grid[row][column].square);
			grid[row][column].square = nullptr;

			row++;
		}
		else if (m == Left)
		{
			if (column == 0)
				return false;

			int prevColumn = column - 1;
			for (int i = 0; i < 4; i++)
			{
				if (grid[row + i][prevColumn].square)
					return false;
			}

			for (int i = 0; i < 4; i++)
			{
				grid[row+i][column].square = nullptr;
				grid[row+i][prevColumn].set_square(&squares[i]);
			}

			column--;
		}
		else
		{
			static int RIGHT_BORDER = COLUMNS - 1;

			if (column == RIGHT_BORDER)
				return false;

			int nextColumn = column + 1;
			for (int i = 0; i < 4; i++)
			{
				if (grid[row + i][nextColumn].square)
					return false;
			}

			for (int i = 0; i < 4; i++)
			{
				grid[row + i][column].square = nullptr;
				grid[row + i][nextColumn].set_square(&squares[i]);
			}

			column++;
		}
	}

	return true;
}