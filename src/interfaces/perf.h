/*  Project name    : A2BF
 *  File name       : interfaces/perf.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_INTERFACES_PERF_H_
#define A2BF_INTERFACES_PERF_H_

#include <string>

#include "models/alphabeta.h"
#include "models/board.h"
#include "models/cell.h"
#include "models/minimax.h"

namespace a2bf {

void PerformMinimax(
    MinimaxSolver& minimax, const Board& init,
    double (*evaluator)(const Board&, CellState), int n, std::string label);
void PerformAlphabeta(
    AlphabetaSolver& alphabeta, const Board& init,
    double (*evaluator)(const Board&, CellState), int n, std::string label);

}  // namespace a2bf

#endif  // A2BF_INTERFACES_PERF_H_
