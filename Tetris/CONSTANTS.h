#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

// squares per tile
constexpr int SPT = 4;

constexpr float WIDTH = 1280.f;
constexpr float HEIGHT = 720.f;

constexpr float COLUMNS = 12.f;
constexpr float ROWS = 20.f;

inline constexpr float SQUARE_SIDE = (HEIGHT - (HEIGHT * 8.f / 100.f)) / ROWS;

inline constexpr float GRID_X = (WIDTH - (COLUMNS * SQUARE_SIDE)) / 2.f;
inline constexpr float GRID_Y = 4.f / 100.f * HEIGHT;

