/*  Project name    : A2BF
 *  File name       : models/board.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <cassert>
#include <string>

#include <models/board.h>

namespace a2bf {

bool Board::PlaceStone(CellState color, int row, int col) {
    assert(color != CellState::kNone);
    assert((0 <= row) && (row < kBoardHeight));
    assert((0 <= col) && (col < kBoardWidth));
    bool succeeds = false;
    if (cells_[row][col].state() == CellState::kNone) {
        cells_[row][col].state(color);
        succeeds = true;
    }
    return succeeds;
}

std::string Board::ToString() const {
    std::string repr;
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            repr.append(cells_[i][j].ToString());
        }
        repr.append("\n");
    }
    return repr;
}

}  // namespace a2bf
