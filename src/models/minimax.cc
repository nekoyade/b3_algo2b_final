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

// DEBUG
#include <iostream>

namespace a2bf {

void MinimaxSolver::Minimax(const Board& init) {
    visited_boards_.clear();
    MinimaxImpl(init, 1, CellState::kDark);
}

double MinimaxSolver::MinimaxImpl(
        const Board& curr, int depth, CellState turn) {
    switch (curr.winner()) {
    case CellState::kDark:
        return std::numeric_limits<double>::infinity();
        break;
    case CellState::kLight:
        return -std::numeric_limits<double>::infinity();
        break;
    default:
        break;
    }
    if (depth >= kDepthLimit) {
        return 0.0;  // TODO: Implement this.
    }
    double m = -std::numeric_limits<double>::infinity();
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            Board next = curr;
            if (!next.PlaceStone(turn, i, j)) { continue; }
                // DEBUG
                std::cout << "depth: " << depth << std::endl;
                std::cout << next.ToString();
                std::cout << next.ToHash() << std::endl;
            if (visited_boards_.find(next.ToHash())
                    != visited_boards_.end()) {
                    // DEBUG
                    std::cout << "visited" << std::endl;
                    std::cout << std::endl;
                continue;
            }
            visited_boards_.insert(next.ToHash());
            double v = -MinimaxImpl(next, depth + 1, NextTurn(turn));
                // DEBUG
                std::cout << "v: " << v << " ";
                std::cout << "(depth: " << depth << ")" << std::endl;
                std::cout << std::endl;
            if (v > m) { m = v; }
        }
    }
    return m;
}

}  // namespace a2bf
