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

int temp();

class Board
{
public:
    Board()
    {
        pieces.resize(8, std::vector<Piece>(8, Piece::EMPTY));
    }

    void Draw()
    {
        for (const auto& row : pieces) {
            for (Piece piece : row) {
                std::cout << static_cast<int>(piece) << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    std::vector<std::vector<Piece>> pieces;
};

}; // namespace chess
