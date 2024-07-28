/*  Project name    : A2BF
 *  File name       : models/game.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_GAME_H_
#define A2BF_MODELS_GAME_H_

#include "models/board.h"

namespace a2bf {

inline constexpr int kDepthLimit = 10;

double EvaluatorA(const Board& board);

}  // namespace a2bf

#endif  // A2BF_MODELS_GAME_H_
