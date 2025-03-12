#pragma once
#include "Tile.h"

// Lead Square is the top left of the squareTile


class SquareTile :
    public Tile
{
public:
    SquareTile(std::vector<std::vector<GridSquare>>& gridRef, bool& emptySpace);

    virtual bool rotate_tile() override;
    virtual bool move_tile(Movement m) override;
    
};

