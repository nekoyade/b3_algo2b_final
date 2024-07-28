/*  Project name    : A2BF
 *  File name       : main.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <iostream>

#include "models/board.h"
#include "models/game.h"
#include "models/minimax.h"

int main() {
    // DEBUG
    a2bf::Board board;

    a2bf::MinimaxSolver minimax;
    std::cout
        << minimax.Minimax(board, a2bf::CellState::kDark, a2bf::EvaluatorA)
        << std::endl;

    /*
    a2bf::CellState turn = a2bf::CellState::kDark;
    int row, col;
    bool succeeds;

    while (board.num_of_empty_cells() > 0) {
        std::cout << "Hash: " << board.ToHash() << std::endl;
        std::cout << "TURN: " << a2bf::CellStateToString(turn) << std::endl;
        std::cout << "Empty grid: " << board.num_of_empty_cells() << std::endl;
        std::cout << "Enter the row number: ";
        while (true) {
            std::cin >> row;
            if (std::cin.good()) {
                if ((0 <= row) && (row < a2bf::kBoardHeight)) {
                    break;
                }
            }
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "  Invalid value; enter the row number again: ";
        }
        std::cout << "Enter the column number: ";
        while (true) {
            std::cin >> col;
            if (std::cin.good()) {
                if ((0 <= col) && (col < a2bf::kBoardWidth)) {
                    break;
                }
            }
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "  Invalid value; enter the column number again: ";
        }
        std::cout << "Place a disk on (row=" << row << ", col=" << col << ")"
            << std::endl;
        succeeds = board.PlaceStone(turn, row, col);
        if (succeeds) {
            std::cout << board.ToString();
            std::cout << "Winner: " << a2bf::CellStateToString(board.winner())
                << std::endl;
            std::cout << std::endl;
            turn = a2bf::NextTurn(turn);
        } else {
            std::cout << "Failure! Please place it on any other grid."
                << std::endl;
        }
    }
    */

    return 0;
}
