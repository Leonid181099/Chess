#include "../include/chess.hpp"

#include <algorithm>
#include <string>
#include <unordered_map>

namespace chess
{

std::ostream& operator<<(std::ostream& os, const Piece& p)
{
    os << static_cast<int>(p);
    return os;
}

template <typename T, typename lambda, typename Arg>
void apply(std::vector<T>& v, lambda l, const Arg& arg)
{
    std::for_each(v[arg].begin(), v[arg].end(), l);
}

template <typename T, typename lambda, typename Arg, typename... Tail>
void apply(std::vector<T>& v, lambda l, const Arg& arg, const Tail&... tail)
{
    std::for_each(v[arg].begin(), v[arg].end(), l);
    apply(v, l, tail...);
}

Board::Board()
{
    pieces.resize(8, std::vector<Piece>(8, Piece::EMPTY));

    pieces[0] = std::vector<Piece>{Piece::ROOK, Piece::KNIGHT, Piece::BISHOP, Piece::QUEEN, Piece::KING, Piece::BISHOP, Piece::KNIGHT, Piece::ROOK};
    pieces[7] = std::vector<Piece>{Piece::ROOK, Piece::KNIGHT, Piece::BISHOP, Piece::QUEEN, Piece::KING, Piece::BISHOP, Piece::KNIGHT, Piece::ROOK};

    auto pawns = [](Piece& p) { // clang-format
        p = Piece::PAWN;
    };

    apply(pieces, pawns, 1, 6);
}

void Board::Draw()
{
    for (const auto& row : pieces) {
        for (auto piece : row) {
            std::cout << piece << " ";
        }
        std::cout << std::endl;
    }
}
}; // namespace chess