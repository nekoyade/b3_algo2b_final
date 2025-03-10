/*  Project name    : A2BF
 *  File name       : models/cell.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_CELL_H_
#define A2BF_MODELS_CELL_H_

#include <string>

namespace a2bf {

enum class CellState : unsigned char {
    kNone,
    kDark,
    kLight,
};

CellState NextTurn(CellState current_turn);

std::string CellStateToString(CellState state);

class Cell {
public:
    Cell() {
        state_ = CellState::kNone;
    }
    ~Cell() {}

    CellState state() const { return state_; }
    void state(CellState state) { state_ = state; }

    std::string ToString() const;

private:
    CellState state_;
};

}  // namespace a2bf

#endif  // A2BF_MODELS_CELL_H_
