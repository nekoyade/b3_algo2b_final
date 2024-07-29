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

double EvaluatorA(const Board& board, CellState turn) {
    double eval = 0.0;
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            // ...
        }
    }
    return eval;
}

}  // namespace a2bf
