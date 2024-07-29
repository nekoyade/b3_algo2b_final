/*  Project name    : A2BF
 *  File name       : models/game.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "models/game.h"

#include <algorithm>
#include <cassert>

#include "models/board.h"
#include "models/cell.h"

namespace a2bf {

double EvaluatorA(const Board& board, CellState turn) {
    assert(turn != CellState::kNone);
    double eval = 0.0;
    const CellArray& cells = board.cells();
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            if (cells[i][j].state() != turn) {
                continue;
            }
            int v1 = board.CountStonesOnLine(turn, i, j, 0, 1);
            int v2 = board.CountStonesOnLine(turn, i, j, 1, 0);
            int v3 = board.CountStonesOnLine(turn, i, j, 1, 1);
            int v4 = board.CountStonesOnLine(turn, i, j, -1, 1);
            int m = std::max({v1, v2, v3, v4});
            if (eval < m) { eval = m; }
        }
    }
    return eval;
}

double EvaluatorB(const Board& board, CellState turn) {
    assert(turn != CellState::kNone);
    double eval = 0.0;
    const CellArray& cells = board.cells();
    CellState nrut = NextTurn(turn);
    double eval_turn = 0.0;
    double eval_nrut = 0.0;
    for (int i = 0; i < kBoardHeight; ++i) {
        for (int j = 0; j < kBoardWidth; ++j) {
            if (cells[i][j].state() == turn) {
                int v1 = board.CountStonesOnLine(turn, i, j, 0, 1);
                int v2 = board.CountStonesOnLine(turn, i, j, 1, 0);
                int v3 = board.CountStonesOnLine(turn, i, j, 1, 1);
                int v4 = board.CountStonesOnLine(turn, i, j, -1, 1);
                int m = std::max({v1, v2, v3, v4});
                if (eval_turn < m) { eval_turn = m; }
            } else if (cells[i][j].state() == nrut) {
                int v1 = board.CountStonesOnLine(nrut, i, j, 0, 1);
                int v2 = board.CountStonesOnLine(nrut, i, j, 1, 0);
                int v3 = board.CountStonesOnLine(nrut, i, j, 1, 1);
                int v4 = board.CountStonesOnLine(nrut, i, j, -1, 1);
                int m = std::max({v1, v2, v3, v4});
                if (eval_nrut < m) { eval_nrut = m; }
            }
        }
    }
    eval = eval_turn - eval_nrut;
    return eval;
}

}  // namespace a2bf
