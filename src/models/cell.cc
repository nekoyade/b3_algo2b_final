/*  Project name    : A2BF
 *  File name       : models/cell.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <cassert>
#include <string>

#include <models/cell.h>

namespace a2bf {

CellState NextTurn(CellState current_turn) {
    assert(
        (current_turn == CellState::kDark)
        || (current_turn == CellState::kLight)
    );
    CellState next_turn;
    if (current_turn == CellState::kDark) {
        next_turn = CellState::kLight;
    } else if (current_turn == CellState::kLight) {
        next_turn = CellState::kDark;
    }
    return next_turn;
}

std::string CellStateToString(CellState state) {
    std::string repr;
    switch (state) {
    case CellState::kNone:
        repr = "None";
        break;
    case CellState::kDark:
        repr = "Dark";
        break;
    case CellState::kLight:
        repr = "Light";
        break;
    default:
        repr = "Unknown";
        break;
    }
    return repr;
}

std::string Cell::ToString() const {
    std::string repr;
    switch (state_) {
    case CellState::kNone:
        repr = ". ";
        break;
    case CellState::kDark:
        repr = "X ";
        break;
    case CellState::kLight:
        repr = "O ";
        break;
    default:
        repr = "? ";
        break;
    }
    return repr;
}

}  // namespace a2bf
