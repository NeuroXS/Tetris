#pragma once
#include "Tile.h"

class TTile :
    public Tile
{
public:
    TTile(std::vector<std::vector<GridSquare>>& gridRef, bool& emptySpace);

    virtual bool rotate_tile() override;
    virtual bool move_tile(Movement m) override;
};

