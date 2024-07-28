/*  Project name    : A2BF
 *  File name       : models/board.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <cassert>
#include <cstddef>
#include <string>

#include <models/board.h>
#include <models/cell.h>

namespace a2bf {

bool Board::PlaceStone(CellState color, int row, int col) {
    assert(color != CellState::kNone);
    assert((0 <= row) && (row < kBoardHeight));
    assert((0 <= col) && (col < kBoardWidth));
    bool succeeds = false;
    if (cells_[row][col].state() == CellState::kNone) {
        cells_[row][col].state(color);
        if (CheckWinOf(color, row, col)) {
            winner_ = color;
        }
        succeeds = true;
    }
    return succeeds;
}

std::size_t Board::ToHash() const {
    std::string repr;
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            switch (cells_[i][j].state()) {
            case CellState::kNone:
                repr.append("0");
                break;
            case CellState::kDark:
                repr.append("1");
                break;
            case CellState::kLight:
                repr.append("2");
                break;
            default:
                repr.append("?");
                break;
            }
        }
    }
    return std::hash<std::string>()(repr);
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

namespace {

bool ExistsWithinTheBoundOfBoard(int row, int col) {
    bool cond_r = (0 <= row) && (row < kBoardHeight);
    bool cond_c = (0 <= col) && (col < kBoardWidth);
    return cond_r && cond_c;
}

int CountStonesOnHalfLine(
        CellState color, const CellArray& cells, int row, int col,
        int delta_row, int delta_col) {
    assert(color != CellState::kNone);
    assert((0 <= row) && (row < kBoardHeight));
    assert((0 <= col) && (col < kBoardWidth));
    assert((-1 <= delta_row) && (delta_row <= 1));
    assert((-1 <= delta_col) && (delta_col <= 1));
    assert((delta_row != 0) || (delta_col != 0));
    int count = 0;
    int r = row + delta_row;
    int c = col + delta_col;
    while (true) {
        if (!ExistsWithinTheBoundOfBoard(r, c)) { break; }
        if (cells[r][c].state() != color) { break; }
        ++count;
        r += delta_row;
        c += delta_col;
    }
    return count;
}

bool ScanLine(
        CellState color, const CellArray& cells, int row, int col,
        int delta_row, int delta_col) {
    assert(color != CellState::kNone);
    assert((0 <= row) && (row < kBoardHeight));
    assert((0 <= col) && (col < kBoardWidth));
    assert(cells[row][col].state() == color);
    assert((-1 <= delta_row) && (delta_row <= 1));
    assert((-1 <= delta_col) && (delta_col <= 1));
    assert((delta_row != 0) || (delta_col != 0));
    int count = 1;
    count += CountStonesOnHalfLine(
        color, cells, row, col, delta_row, delta_col);
    count += CountStonesOnHalfLine(
        color, cells, row, col, -delta_row, -delta_col);
    return count >= kLengthOfGomokuLine;
}

}  // namespace

bool Board::CheckWinOf(CellState color, int row, int col) const {
    assert(color != CellState::kNone);
    assert((0 <= row) && (row < kBoardHeight));
    assert((0 <= col) && (col < kBoardWidth));
    assert(cells_[row][col].state() == color);
    return (
        ScanLine(color, cells_, row, col, 0, 1)
        || ScanLine(color, cells_, row, col, 1, 0)
        || ScanLine(color, cells_, row, col, 1, 1)
        || ScanLine(color, cells_, row, col, -1, 1)
    );
}

}  // namespace a2bf
