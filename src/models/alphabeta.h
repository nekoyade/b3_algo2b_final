/*  Project name    : A2BF
 *  File name       : models/alphabeta.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2BF_MODELS_ALPHABETA_H_
#define A2BF_MODELS_ALPHABETA_H_

#include <cstddef>
#include <unordered_map>

#include "models/board.h"
#include "models/cell.h"

namespace a2bf {

class AlphabetaSolver {
public:
    AlphabetaSolver() {
        call_counter_ = 0ll;
    }
    ~AlphabetaSolver() {}

    double Alphabeta(
        const Board& init, CellState turn,
        double (*evaluator)(const Board&, CellState));

    long long int call_counter() const { return call_counter_; }

private:
    double AlphabetaImpl(
        const Board& curr, int depth, CellState turn,
        double (*evaluator)(const Board&, CellState), double alpha,
        double beta);

    std::unordered_map<std::size_t, double> evals_;

    long long int call_counter_;
};

}  // namespace a2bf

#endif  // A2BF_MODELS_ALPHABETA_H_
