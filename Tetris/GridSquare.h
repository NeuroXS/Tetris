#pragma once
#include "CONSTANTS.h"

class GridSquare
{
public:
    GridSquare();
    void set_square(RectangleShape* sq);

    sf::RectangleShape* square;

    float x, y;
};

