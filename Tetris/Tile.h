#pragma once
#include <vector>
#include "GridSquare.h"

// Abstract class
class Tile
{
protected:
	enum Rotation { North, South, East, West };

public:
	Tile(std::vector<std::vector<GridSquare>>& gridRef, const std::pair<int,int>& columnBounds);

	enum Movement { Left, Right, Down };

	// rotate clock wise
	virtual bool rotate_tile() = 0;

	
	virtual bool move_tile(Movement m) = 0;
	
	Rotation rotation;

	// position of the tile
	unsigned char row;
	unsigned char column;

	// refrence to grid
	std::vector<std::vector<GridSquare>>& grid;

	// Tile squares
	std::vector<RectangleShape> squares;

	// collision state
	bool collided;
};

