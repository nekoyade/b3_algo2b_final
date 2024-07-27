/*  Project name    : A2BF
 *  File name       : models/cell.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_CELL_H_
#define A2BF_MODELS_CELL_H_

namespace a2bf {

enum class CellState : unsigned char {
    kNone,
    kDark,
    kLight,
};

class Cell {
public:
    Cell() {
        state_ = CellState::kNone;
    }
    ~Cell() {}

private:
    CellState state_;
};

}  // namespace a2bf

#endif  // A2BF_MODELS_CELL_H_
