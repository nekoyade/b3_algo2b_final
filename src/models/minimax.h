/*  Project name    : A2BF
 *  File name       : models/minimax.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_MINIMAX_H_
#define A2BF_MODELS_MINIMAX_H_

#include <cstddef>
#include <unordered_set>

#include <models/board.h>

namespace a2bf {

inline constexpr int kDepthLimit = 10;

class MinimaxSolver {
public:
    MinimaxSolver() {}
    ~MinimaxSolver() {}

    void Minimax(const Board& init);

private:
    double MinimaxImpl(const Board& curr, int depth, CellState turn);

    std::unordered_set<std::size_t> visited_boards_;
};

}  // namespace a2bf

#endif  // A2BF_MODELS_MINIMAX_H_
