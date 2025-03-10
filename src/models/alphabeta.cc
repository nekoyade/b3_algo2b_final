/*  Project name    : A2BF
 *  File name       : models/alphabeta.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "models/alphabeta.h"

#include <limits>

#include "models/board.h"
#include "models/cell.h"
#include "models/game.h"

namespace a2bf {

double AlphabetaSolver::Alphabeta(
        const Board& init, CellState turn,
        double (*evaluator)(const Board&, CellState)) {
    evals_.clear();
    call_counter_ = 0ll;
    return AlphabetaImpl(
        init, 1, turn, evaluator, -std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity());
}

double AlphabetaSolver::AlphabetaImpl(
        const Board& curr, int depth, CellState turn,
        double (*evaluator)(const Board&, CellState), double alpha,
        double beta) {
    call_counter_ += 1;
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
        return evaluator(curr, turn);
    }
    double m = alpha;
    bool prunes = false;
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            Board next = curr;
            if (!next.PlaceStone(turn, i, j)) { continue; }
            double v;
            if (evals_.find(next.ToHash()) != evals_.end()) {
                v = evals_.at(next.ToHash());
            } else {
                v = -AlphabetaImpl(
                    next, depth + 1, NextTurn(turn), evaluator, -beta, -m);
                evals_.insert({next.ToHash(), v});
            }
            if (v > m) {
                m = v;
                if (m >= beta) {
                    prunes = true;
                    break;
                }
            }
        }
        if (prunes) {
            break;
        }
    }
    return m;
}

}  // namespace a2bf
