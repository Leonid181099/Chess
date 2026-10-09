#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

namespace chess
{

enum class Piece {
    EMPTY = 0,
    PAWN = 1,
    BISHOP = 2,
    KNIGHT = 3,
    ROOK = 4,
    QUEEN = 5,
    KING = 6,
};

class Board
{
public:
    Board();
    void Draw();

private:
    std::vector<std::vector<Piece>> pieces;
};

}; // namespace chess
