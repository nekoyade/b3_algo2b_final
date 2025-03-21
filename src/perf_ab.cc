/*  Project name    : A2BF
 *  File name       : perf_ab.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <iostream>

#include "interfaces/perf.h"

#include "models/alphabeta.h"
#include "models/board.h"
#include "models/game.h"

int main() {
    std::cout << "*** Performance of evaluation for gomoku-narabe ***"
        << std::endl;
    std::cout << "Depth limit: " << a2bf::kDepthLimit << std::endl;
    std::cout << std::endl;

    a2bf::Board board;

    a2bf::AlphabetaSolver alphabeta;

    std::cout << "Evaluation by alphabeta" << std::endl;
    a2bf::PerformAlphabeta(alphabeta, board, a2bf::EvaluatorA, 3, "A");
    a2bf::PerformAlphabeta(alphabeta, board, a2bf::EvaluatorB, 3, "B");

    return 0;
}
