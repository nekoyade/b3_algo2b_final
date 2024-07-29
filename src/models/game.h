/*  Project name    : A2BF
 *  File name       : models/game.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_GAME_H_
#define A2BF_MODELS_GAME_H_

#include "models/board.h"
#include "models/cell.h"

namespace a2bf {

#ifdef SANMOKU
inline constexpr int kDepthLimit = 10;
#else
inline constexpr int kDepthLimit = 4;
#endif

double EvaluatorA(const Board& board, CellState turn);

}  // namespace a2bf

#endif  // A2BF_MODELS_GAME_H_
