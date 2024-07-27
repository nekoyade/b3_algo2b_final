/*  Project name    : A2BF
 *  File name       : main.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <iostream>

#include <models/board.h>

int main() {
    // DEBUG
    a2bf::Board board;
    a2bf::CellState turn = a2bf::CellState::kDark;
    int row, col;
    bool succeeds;

    while (true) {
        std::cout << "TURN: ";
        switch (turn) {
        case a2bf::CellState::kDark:
            std::cout << "Dark";
            break;
        case a2bf::CellState::kLight:
            std::cout << "Light";
            break;
        default:
            std::cout << "?";
            break;
        }
        std::cout << std::endl;
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
            std::cout << board.ToString() << std::endl;
            std::cout << std::endl;
            if (turn == a2bf::CellState::kDark) {
                turn = a2bf::CellState::kLight;
            } else if (turn == a2bf::CellState::kLight) {
                turn = a2bf::CellState::kDark;
            }
        } else {
            std::cout << "Failure! Please place it on any other grid."
                << std::endl;
        }
    }

    return 0;
}
