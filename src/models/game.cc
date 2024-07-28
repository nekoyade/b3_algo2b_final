/*  Project name    : A2BF
 *  File name       : models/game.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "models/game.h"

#include "models/board.h"
#include "models/cell.h"

namespace a2bf {

double EvaluatorA(const Board& board) {
    double eval = 0.0;
    const CellArray& cells = board.cells();
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            switch (cells[i][j].state()) {
            case CellState::kDark:
                eval += 1.0;
                break;
            case CellState::kLight:
                eval -= 1.0;
                break;
            default:
                break;
            }
        }
    }
    return eval;
}

}  // namespace a2bf
