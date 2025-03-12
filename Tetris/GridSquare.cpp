#include "GridSquare.h"
#include "Utility.h"

GridSquare::GridSquare()
	:square{ nullptr },
	x{ 0 },
	y{0}
{

	
}

void GridSquare::set_square(RectangleShape* sq)
{
	square = sq;
	sq->setPosition({ x,y });
}