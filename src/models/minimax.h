/*  Project name    : A2BF
 *  File name       : models/minimax.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_MINIMAX_H_
#define A2BF_MODELS_MINIMAX_H_

#include <models/board.h>

namespace a2bf {

class MinimaxSolver {
public:
    MinimaxSolver() {}
    ~MinimaxSolver() {}

    void Minimax(const Board& init);

private:
    // ...
};

}  // namespace a2bf

#endif  // A2BF_MODELS_MINIMAX_H_
