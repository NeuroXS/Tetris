#pragma once
#include "Tile.h"

class BarTile :
    public Tile
{
public:
    BarTile(std::vector<std::vector<GridSquare>>& gridRef, bool& emptySpace);

    virtual bool rotate_tile() override;
    virtual bool move_tile(Movement m) override;
};

