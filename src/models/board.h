/*  Project name    : A2BF
 *  File name       : models/board.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <array>

#include <models/cell.h>

#ifndef A2BF_MODELS_BOARD_H_
#define A2BF_MODELS_BOARD_H_

namespace a2bf {

inline constexpr int kBoardWidth = 0;
inline constexpr int kBoardHeight = 0;

using CellArray = std::array<std::array<Cell, kBoardWidth>, kBoardHeight>;

class Board {
public:
    Board() {}
    ~Board() {}

private:
    CellArray cells_;
};

}  // namespace a2bf

#endif  // A2BF_MODELS_BOARD_H_
