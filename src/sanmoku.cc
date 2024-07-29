/*  Project name    : A2BF
 *  File name       : sanmoku.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <iostream>

#include "models/alphabeta.h"
#include "models/board.h"
#include "models/cell.h"
#include "models/game.h"
#include "models/minimax.h"

int main() {
    std::cout << "*** Evaluation for sanmoku-narabe ***" << std::endl;

    a2bf::Board board;
    a2bf::MinimaxSolver minimax;
    a2bf::AlphabetaSolver alphabeta;

    std::cout << "Minimax:   "
        << minimax.Minimax(board, a2bf::CellState::kDark, a2bf::EvaluatorA)
        << std::endl;
    std::cout << "Alphabeta: "
        << alphabeta.Alphabeta(board, a2bf::CellState::kDark, a2bf::EvaluatorA)
        << std::endl;

    return 0;
}
