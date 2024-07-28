/*  Project name    : A2BF
 *  File name       : models/minimax.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "models/minimax.h"

#include <limits>

#include "models/board.h"
#include "models/cell.h"
#include "models/game.h"

namespace a2bf {

double MinimaxSolver::Minimax(
        const Board& init, CellState turn,
        double (*evaluator)(const Board&)) {
    evals_.clear();
    return MinimaxImpl(init, 1, turn, evaluator);
}

double MinimaxSolver::MinimaxImpl(
        const Board& curr, int depth, CellState turn,
        double (*evaluator)(const Board&)) {
    switch (curr.winner()) {
    case CellState::kDark:
    case CellState::kLight:
        if (curr.winner() == turn) {
            return std::numeric_limits<double>::infinity();
        } else {
            return -std::numeric_limits<double>::infinity();
        }
        break;
    default:
        if (curr.num_of_empty_cells() <= 0) { return 0.0; }
        break;
    }
    if (depth >= kDepthLimit) {
        return evaluator(curr);
    }
    double m = -std::numeric_limits<double>::infinity();
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            Board next = curr;
            if (!next.PlaceStone(turn, i, j)) { continue; }
            double v;
            if (evals_.find(next.ToHash()) != evals_.end()) {
                v = evals_.at(next.ToHash());
            } else {
                v = -MinimaxImpl(next, depth + 1, NextTurn(turn), evaluator);
                evals_.insert({next.ToHash(), v});
            }
            if (v > m) { m = v; }
        }
    }
    return m;
}

}  // namespace a2bf
