/*  Project name    : A2BF
 *  File name       : models/cell.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <string>

#include <models/cell.h>

namespace a2bf {

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
