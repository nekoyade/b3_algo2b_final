/*  Project name    : A2BF
 *  File name       : models/board.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_BOARD_H_
#define A2BF_MODELS_BOARD_H_

#include <array>
#include <cstddef>
#include <string>

#include "models/cell.h"

namespace a2bf {

#ifdef SANMOKU
inline constexpr int kBoardWidth = 3;
inline constexpr int kBoardHeight = 3;
#else
inline constexpr int kBoardWidth = 9;
inline constexpr int kBoardHeight = 9;
#endif

using CellArray = std::array<std::array<Cell, kBoardWidth>, kBoardHeight>;

#ifdef SANMOKU
inline constexpr int kLengthOfGomokuLine = 3;
#else
inline constexpr int kLengthOfGomokuLine = 5;
#endif

class Board {
public:
    Board() {
        winner_ = CellState::kNone;
        num_of_empty_cells_ = kBoardHeight*kBoardWidth;
    }
    ~Board() {}

    const CellArray& cells() const { return cells_; }

    CellState winner() const { return winner_; }
    int num_of_empty_cells() const { return num_of_empty_cells_; }

    bool PlaceStone(CellState color, int row, int col);

    std::size_t ToHash() const;

    std::string ToString() const;

private:
    bool CheckWinOf(CellState color, int row, int col) const;

    CellArray cells_;

    CellState winner_;
    int num_of_empty_cells_;
};

}  // namespace a2bf

#endif  // A2BF_MODELS_BOARD_H_
