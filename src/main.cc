/*  Project name    : A2BF
 *  File name       : main.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <iostream>

#include <models/board.h>

// DEBUG
#include <models/cell.h>

int main() {
    std::cout << "hello world" << std::endl;
    std::cout << "include models/board.h" << std::endl;

    // DEBUG
    a2bf::Cell cell;
    std::cout << cell.ToString() << std::endl;
    std::cout << sizeof(a2bf::Cell) << std::endl;
    a2bf::Board board;
    std::cout << board.ToString() << std::endl;
    std::cout << sizeof(a2bf::Board) << std::endl;

    return 0;
}
