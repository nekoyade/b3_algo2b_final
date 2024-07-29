/*  Project name    : A2BF
 *  File name       : gomoku.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <cassert>
#include <iostream>
#include <string>

#include "models/alphabeta.h"
#include "models/board.h"
#include "models/cell.h"
#include "models/game.h"

int ReceiveIntFromInput(int min, int max, std::string name) {
    assert(min <= max);
    int result;
    while (true) {
        std::cout << "Enter " << name << " ";
        std::cout << "[" << min << "-" << max << "] > ";
        std::cin >> result;

        if (std::cin.good()) {
            if ((min <= result) && (result <= max)) {
                break;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Please input an integer." << std::endl;
        }
    }
    return result;
}

int main() {
    std::cout << "*** Gomoku-narabe ***" << std::endl;
    std::cout << std::endl;

    bool continues = true;

    a2bf::AlphabetaSolver alphabeta;

    while (continues) {
        a2bf::Board board;
        a2bf::CellState turn = a2bf::CellState::kDark;

        while (true) {
            if (board.num_of_empty_cells() <= 0) {
                std::cout << "No empty grids." << std::endl;
                break;
            }
            if (board.winner() != a2bf::CellState::kNone) {
                break;
            }

            std::cout << "TURN: " << a2bf::CellStateToString(turn)
                << std::endl;
            std::cout << board.ToString();

            int row = ReceiveIntFromInput(
                1, a2bf::kBoardHeight, "the row number") - 1;
            int col = ReceiveIntFromInput(
                1, a2bf::kBoardWidth, "the column number") - 1;

            if (board.PlaceStone(turn, row, col)) {
                std::cout << "Placed a stone at ";
                std::cout << "(" << row + 1 << ", " << col + 1 << ")."
                    << std::endl;

                std::cout << "Superiority: ";
                double eval =
                    alphabeta.Alphabeta(board, turn, a2bf::EvaluatorA);
                if (eval < 0.0) {
                    std::cout << a2bf::CellStateToString(a2bf::NextTurn(turn));
                } else if (0.0 < eval) {
                    std::cout << a2bf::CellStateToString(turn);
                } else {
                    std::cout << "50-50";
                }
                std::cout << " (" << eval << ")" << std::endl;

                turn = a2bf::NextTurn(turn);
            } else {
                std::cout << "  [!] Failed in placing a stone at ";
                std::cout << "(" << row + 1 << ", " << col + 1 << ")."
                    << std::endl;
                std::cout << "  Please place it on any other grid."
                    << std::endl;
            }
            std::cout << std::endl;
        }

        switch (board.winner()) {
        case a2bf::CellState::kDark:
        case a2bf::CellState::kLight:
            std::cout << "WINNER: " << a2bf::CellStateToString(board.winner())
                << std::endl;
            break;
        default:
            std::cout << "DRAW" << std::endl;
            break;
        }
        std::cout << std::endl;

        while (true) {
            std::cout << "Continue? [y/n] > ";

            char respond;
            std::cin >> respond;
            if (std::cin.good()) {
                if (respond == 'y') {
                    break;
                } else if (respond == 'n') {
                    continues = false;
                    break;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cout << "Invalid input." << std::endl;
            }
        }
    }

    return 0;
}
